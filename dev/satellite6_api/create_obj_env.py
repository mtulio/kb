#!/usr/bin/python

# Red Hat Satellite - API Guide - 4.2.1. Creating Objects Using Python
# Link: https://access.redhat.com/documentation/en-US/Red_Hat_Satellite/6.1/html-single/API_Guide/index.html#idm4983248
#
# The following script connects to the Red Hat Satellite 6 API and creates a new organization, then creates three environments 
# in the new  organization. If the organization already exists, the script uses that organization. If any of the environments 
# already exist in the organization, the script raises an error and quits.
#
# NOTE:
#  This script requires the requests and json modules.
#
# WARNING: 
#  This script does not use SSL communication for interacting with the REST API and is provided here only as a demonstration.

import json
import sys


try:
    import requests
except ImportError:
    print "Please install the python-requests module."
    sys.exit(-1)

# URL to your Satellite 6 server
URL = "https://satellite6.example.com"
# URL for the API to your deployed Satellite 6 server
SAT_API = "%s/katello/api/v2/" % URL
# Katello-specific API
KATELLO_API = "%s/katello/api/" % URL
POST_HEADERS = {'content-type': 'application/json'}
# Default credentials to login to Satellite 6
USERNAME = "admin"
PASSWORD = "changeme"
# Ignore SSL for now
SSL_VERIFY = False

# Name of the organization to be either created or used
ORG_NAME = "MyOrg"
# Name for life cycle environments to be either created or used
ENVIRONMENTS = ["Development", "Testing", "Production"]


def get_json(location):
    """
    Performs a GET using the passed URL location
    """

    r = requests.get(location, auth=(USERNAME, PASSWORD), verify=SSL_VERIFY)

    return r.json()


def post_json(location, json_data):
    """
    Performs a POST and passes the data to the URL location
    """

    result = requests.post(
        location,
        data=json_data,
        auth=(USERNAME, PASSWORD),
        verify=SSL_VERIFY,
        headers=POST_HEADERS)

    return result.json()


def main():
    """
    Main routine that creates or re-uses an organization and
    life cycle environments. If life cycle environments already
    exist, exit out.
    """

    # Check if our organization already exists
    org = get_json(SAT_API + "organizations/" + ORG_NAME)

    # If our organization is not found, create it
    if org.get('error', None):
        org_id = post_json(
            SAT_API + "organizations/",
            json.dumps({"name": ORG_NAME}))["organization"]["id"]
        print "Creating organization: \t" + ORG_NAME
    else:
        # Our organization exists, so let's grab it
        org_id = org['id']
        print "Organization '%s' exists." % ORG_NAME

    # Now, let's fetch all available life cycle environments for this org...
    envs = get_json(
        SAT_API + "organizations/" + str(org_id) + "/environments/")

    # ... and add them to a dictionary, with respective 'Prior' environment
    prior_env_id = 0
    env_list = {}
    for env in envs['results']:
        env_list[env['id']] = env['name']
        prior_env_id = env['id'] if env['name'] == "Library" else prior_env_id

    # Exit the script if at least one life cycle environment already exists
    if all(environment in env_list.values() for environment in ENVIRONMENTS):
        print "ERROR: One of the Environments is not unique to organization"
        sys.exit(-1)

    # Create life cycle environments
    for environment in ENVIRONMENTS:
        new_env_id = post_json(
            SAT_API + "organizations/" + str(org_id) + "/environments/",
            json.dumps(
                {
                    "name": environment,
                    "organization_id": org_id,
                    "prior": prior_env_id}
            ))["id"]

        print "Creating environment: \t" + environment
        prior_env_id = new_env_id


if __name__ == "__main__":
    main()
