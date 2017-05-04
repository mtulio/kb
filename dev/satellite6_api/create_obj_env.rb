#!/usr/bin/ruby

# Red Hat Satellite - API Guide - 4.1.1. Creating Objects Using Ruby
# Link: https://access.redhat.com/documentation/en-US/Red_Hat_Satellite/6.1/html-single/API_Guide/index.html#idp72062560
#
# The following script connects to the Red Hat Satellite 6 API and creates a new organization, then creates three environments 
# in the new  organization. If the organization already exists, the script uses that organization. If any of the environments 
# already exist in the organization, the script raises an error and quits.
#
# NOTE:
#  This script requires the rest-client and json Ruby gems.
#
# WARNING: 
#  This script does not use SSL communication for interacting with the REST API and is provided here only as a demonstration.

require 'rest-client'
require 'json'

url = 'https://satellite6.example.com/api/v2/'
katello_url = 'https://satellite6.example.com/katello/api/v2/'
$username = 'admin'
$password = 'changeme'

org_name = "MyOrg"
environments = ["Development","Testing","Production"]

def get_json(location)
    response = RestClient::Request.new(
        :method => :get,
        :url => location,
        :user => $username,
        :password => $password,
        :headers => { :accept => :json,
        :content_type => :json }
    ).execute
    results = JSON.parse(response.to_str)
end

def post_json(location, json_data)
    response = RestClient::Request.new(
        :method => :post,
        :url => location,
        :user => $username,
        :password => $password,
        :headers => { :accept => :json,
        :content_type => :json},
        :payload => json_data
    ).execute
    results = JSON.parse(response.to_str)
end

orgs = get_json(url+"organizations")
org_list = {}
orgs['results'].each do |org|
    org_list[org['id']] = org['name']
end

if !org_list.has_value?(org_name)
    org_id = post_json(url+"organizations", JSON.generate({"name"=> org_name}))["organization"]["id"]
    puts "Creating organization: \t" + org_name
else
    org_id = org_list.key(org_name)
    puts "Organization \"" + org_name + "\" exists"
end

envs = get_json(katello_url+"organizations/" + org_id.to_s + "/environments")
env_list = {}
envs['results'].each do |env|
    env_list[env['id']] = env['name']
end
prior_env_id = env_list.key("Library")

environments.each do |e|
    if env_list.has_value?(e)
        puts "ERROR: One of the Environments is not unique to organization"
        exit()
    end
end

environments.each do |environment|
    new_env_id = post_json(katello_url+"organizations/" + org_id.to_s + "/environments", JSON.generate({"name" => environment, "organization_id" => org_id,"prior" => prior_env_id}))["id"]
    puts "Creating environment: \t" + environment
    prior_env_id = new_env_id
end
exit()
