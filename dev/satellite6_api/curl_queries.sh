#!/bin/bash

# Red Hat Satellite - API Guide - 4.3. API EXAMPLES USING CURL
# Link: https://access.redhat.com/documentation/en-US/Red_Hat_Satellite/6.1/html-single/API_Guide/index.html#curl-examples
#
# This section describes how to use curl to perform various tasks using the Satellite API. 
# The first section describes simple queries, such as listing general host information, searching for facts, 
# and using pattern matching. 
# The second section describes how to modify Satellite resources, with examples of how to upload and import 
# content to your Satellite server.
#

SATELLITE6_SERVER="satellite6.example.com"
SAT6_USER="admin"
SAT6_PASS="password"

# 4.3.1. Performing Simple Queries
# The following examples describe how to use curl to search for information about your Satellite deployment. 
# These examples include both the actual command and some sample output, and example values for user names and passwords. 
# Expect different results for each deployment. These examples also use the python -mjson.tool command to format the output.
#
## NOTE:
#  Be aware that if you use the -s (silent) option with curl that you will not see a progress meter or any error messages.
#
#  If you use the -k (insecure) option, you need to use HTTPS and also include the -u (user name) option. You can use the 
# form -u username[:password] or, if you do not include the password, the command prompts you to enter it. Red Hat 
# recommends that you do not include the password as part of the command, because it then becomes part of your shell history 
# and might present a security risk. These examples include the password only for the sake of simplicity.

## Retrieving a List of Resources
### The following is a basic query that returns a list of resources. Such requests return a list of data wrapped in metadata, 
### while other request types only return the actual object.
curl -X GET -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts | python -mjson.tool

## Running a Generic Host Query
### The following query returns information for the host Satellite:
curl -X GET -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts/${SATELLITE6_SERVER} | python -mjson.tool

## Searching for Facts for a Specific Host
### The following query returns all facts for the host Satellite:
curl -X GET -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts/${SATELLITE6_SERVER}/facts | python -mjson.tool

## Searching all Hosts for Matching Patterns
### The following query returns all hosts that match the pattern "example":
curl -X GET -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts?search=example | python -mjson.tool

## Searching for all Hosts in a Specific Environment
### The following query returns all hosts in the "production" environment:
curl -X GET -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts?search=environment=production | python -mjson.tool

## Searching for all Hosts with a Specific Fact Value
### The following query returns all hosts with a model name "RHEV Hypervisor":
curl -X GET -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts?search=model=\"RHEV+Hypervisor\" | python -mjson.tool

############################
# 4.3.2. Creating and Modifying Resources
# You can use the Satellite API to manipulate resources on the Satellite server. These API calls 
# require that you pass various parameters beyond the simple user name, password, and URI that you want to query. 
# For example, to upload content to your Satellite server, or to modify Satellite resources, you need to 
# include extra information in the header when you construct your request.
#
# You can specify the version of the API either in the header, as described in the following examples, or as 
# part of the URL. For example, https://satellite6.example.com/api/v2/architectures is the equivalent 
# of using Accept:version=2 in the request header. The URL specification takes precedence.
#
## IMPORTANT
# If you do not specify an API version, version 1 is used, even though it is not supported. If you specify version 1, 
# you might receive an error message or receive incorrect data. Both of these issues have been addressed upstream 
# and will be available in an upcoming release. Red Hat recommends that you always specify version 2 of the API, 
# either in the header or in the URL.


## The following is the basic syntax for a POST request:
# $ curl -H "Accept:application/json,version=2" -H "Content-Type:application/json" -X POST -u username[:password] [-k] -d json-formatted-data  satellite-url


## For example, to create a new architecture, you can use the following example request:
curl -H "Accept:application/json,version=2" -H "Content-Type:application/json" -X POST -u ${SAT6_USER}:${SAT6_PASS} -k -d "{\"architecture\":{\"name\":\"i686\"}}" https://${SATELLITE6_SERVER}/api/architectures


## You can use the following command to verify that the architecture was created:
curl -X GET -u ${SAT6_USER}:${SAT6_PASS} -k https://${SATELLITE6_SERVER}/api/v2/architectures | python -mjson.tool


## You can also use hammer on the Satellite server to verify the results:
hammer -u ${SAT6_USER} -p ${SAT6_PASS} architecture list


##########
# 4.3.2.1. Uploading Content to the Satellite Server
# Two methods exist for uploading content to your Satellite server. The first method is more straightforward 
# but due to web server configuration limitations, the maximum file size that you can upload is about 30 MB. 
# If you try to upload larger files, the Satellite server returns an error. Satellite 6 supports uploading 
# very large files, but the process is slightly more complex. This section describes how to use curl with 
# the Satellite 6 API to upload and import large files to your Satellite server. This process involves 
# four steps:
# 1) Create an upload request.
# 2) Upload the content.
# 3) Import the content.
# 4) Delete the upload request.


## 1) Creating the Upload Request
# The following example command creates an upload request that you can use to upload your content. Ensure you 
# modify the example parameters to suit your deployment:
curl -H "Accept:application/json,version=2" -H "Content-Type:application/json" -X POST -u ${SAT6_USER}:${SAT6_PASS} -k -d "{}" https://${SATELLITE6_SERVER}/katello/api/repositories/3/content_uploads

### NOTE:
# Even though this command uses a POST method, it does not actually pass any data, as evidenced 
# by the empty data string ("{}"). The command creates an upload_id, but no data is passed to 
# the Satellite server to achieve this.
#
# Make a note of the upload_id value; you need this value when you upload your content to the Satellite server.

UPLOAD_ID="0be156b1-f373-4cad-89d0-924f8f4491d2"

## 2) Uploading Your Content
# Ensure you use the correct MIME type when you upload data. The "application/json" MIME type is used for 
# the majority of requests to Satellite 6.
#
# The following example illustrates how to combine the upload_id, MIME type, and other parameters to upload content:
curl -H "Accept:application/json,version=2" -H "Content-Type:multipart/form-data" -X PUT -u ${SAT6_USER}:${SAT6_PASS} -k --data-urlencode "content@/home/sat6user/rpmbuild/RPMS/noarch/python-scripttest-1.1.1-1.fc21.noarch.rpm" --data-urlencode offset=0 https://${SATELLITE6_SERVER}/katello/api/repositories/3/content_uploads/${UPLOAD_ID}

### NOTE:
# You can make this request multiple times to upload large files. Break the content into 
# smaller pieces (for example, 5 MB, using a tool such as split), and increment the offset in bytes.

## 3) Importing the Uploaded Content
# After you have uploaded the content to the Satellite server, you need to import it 
# into the appropriate repository. Until you complete this step, the Satellite server will not be aware of the 
# new content.

curl -H "Accept:application/json,version=2" -H "Content-Type:application/json" -X PUT -u ${SAT6_USER}:${SAT6_PASS} -k -d "{\"upload_ids\":[\"${UPLOAD_ID}\"]}" https://${SATELLITE6_SERVER}/katello/api/repositories/3/import_uploads

## 4) Deleting the Upload Request
# After you have successfully uploaded and imported your content, you can delete the upload request. 
# This frees any temporary disk space that was used during the upload.

curl -H "Accept:application/json,version=2" -H "Content-Type:application/json" -X DELETE -d "{}" -u ${SAT6_USER}:${SAT6_PASS} -k https://${SATELLITE6_SERVER}/katello/api/repositories/3/content_uploads/${UPLOAD_ID}



######
# 4.4. LOCATING AND USING OTHER SEARCH TERMS
## https://access.redhat.com/documentation/en-US/Red_Hat_Satellite/6.1/html-single/API_Guide/index.html#idp5279120

curl -s -k -u ${SAT6_USER}:${SAT6_PASS} https://${SATELLITE6_SERVER}/api/v2/hosts?search=os_description=\"RHEL+Server+6.6\" | python -mjson.tool


####
# Local documentation can be found on your server: https://YOUR_SATELLITE/apidoc/v2.html

