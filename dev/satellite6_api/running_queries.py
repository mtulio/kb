#!/usr/bin/python

# Red Hat Satellite - API Guide - 4.2.2. Running Queries Using Python
# Link: https://access.redhat.com/documentation/en-US/Red_Hat_Satellite/6.1/html-single/API_Guide/index.html#idp10992432
#
# You can create and run a Python script to achieve the same results as those described in Section 4.3, “API Examples 
# Using Curl”(https://access.redhat.com/documentation/en-US/Red_Hat_Satellite/6.1/html-single/API_Guide/index.html#curl-examples). 
# The following example script describes this approach. First, create an executable file called sat6api.py and then add the 
# following content:
#

import json
import sys
try:
    import requests
except ImportError:
    print "Please install the python-requests module."
    sys.exit(-1)

SAT_API = 'https://satellite6.example.com/api/v2/'
USERNAME = "admin"
PASSWORD = "password"
SSL_VERIFY = False   # Ignore SSL for now

def get_json(url):
    # Performs a GET using the passed URL location
    r = requests.get(url, auth=(USERNAME, PASSWORD), verify=SSL_VERIFY)
    return r.json()

def get_results(url):
    jsn = get_json(url)
    if jsn.get('error'):
        print "Error: " + jsn['error']['message']
    else:
        if jsn.get('results'):
            return jsn['results']
        elif 'results' not in jsn:
            return jsn
        else:
            print "No results found"
    return None

def display_all_results(url):
    results = get_results(url)
    if results:
        print json.dumps(results, indent=4, sort_keys=True)

def display_info_for_hosts(url):
    hosts = get_results(url)
    if hosts:
        for host in hosts:
            print "ID: %-10d Name: %-30s IP: %-20s OS: %-30s" % (host['id'], host['name'], host['ip'], host['operatingsystem_name'])

def main():
    host = 'satellite6.example.com'
    print "Displaying all info for host %s ..." % host
    display_all_results(SAT_API + 'hosts/' + host)

    print "Displaying all facts for host %s ..." % host
    display_all_results(SAT_API + 'hosts/%s/facts' % host)

    host_pattern = 'example'
    print "Displaying basic info for hosts matching pattern '%s'..." % host_pattern
    display_info_for_hosts(SAT_API + 'hosts?search=' + host_pattern)

    environment = 'production'
    print "Displaying basic info for hosts in environment %s..." % environment
    display_info_for_hosts(SAT_API + 'hosts?search=environment=' + environment)

    model = 'RHEV Hypervisor'
    print "Displaying basic info for hosts with model name %s..." % model
    display_info_for_hosts(SAT_API + 'hosts?search=model="' + model + '"')

if __name__ == "__main__":
    main()


