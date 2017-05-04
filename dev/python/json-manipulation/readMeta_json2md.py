#! /usr/bin/python

#> IMPORT
##> JSON lib will read JSON metadata
##> AST lib will parse (and remove) unicode string readed from JSON

import json, ast
import os
from pprint import pprint

####################################

def getJson(file_metadata):
  #> JSON file
  #file_metadata = 'metadata.json'
  #> READ JSON file
  with open(file_metadata) as data_file:    
    data_jsonU = json.load(data_file)

  pprint(data_jsonU)
  
  #> PARSING JSON data
  # remove literal 'u'
  #print "JSON Fail: ", json.loads(json.dumps(data))
  #print "AST Win:", ast.literal_eval(json.dumps(data))
  
  #pprint(data)
  #pprint(data_ast['requirements'][0]['name'])
  #pprint(data_ast['requirements'][0]['version_requirement'])

  #> PRINT VALUES
#  if file_metadata == 'motd/metadata.json':
#  pprint(data_jsonU)

  return ast.literal_eval(json.dumps(data_jsonU))

#######################
# Parse JSON flow
## Assign values to global envs
def parseJSON(data):

  global data_name, data_version, data_author, data_summary, data_license, \
    data_source, data_project_page, data_issues_url, data_description, data_os_support, \
    data_requirements, data_dependencies, data_tags

#  data_name = data_version = data_author = data_summary = data_license = \
#    data_source = data_project_page = data_issues_url = data_description = data_os_support = \
#    data_requirements = data_dependencies = ''

  ##> Get all keys available on metadata
  metadata_keys = data.keys()
  count = 0

  ###> Get metadata keys
  for key in metadata_keys:
    count += 1
    if key == 'name':
      data_name = data['name']
    if key == 'version':
      data_version = data['version']
    if key == 'author':
      data_author = data['author']
    if key == 'summary':
      data_summary = data['summary']
    if key == 'license':
      data_license = data['license']
    if key == 'source':
      data_source = data['source']
    if key == 'project_page':
      data_project_page = data['project_page']
    if key == 'issues_url':
      data_issues_url = data['issues_url']
    if key == 'description':
      data_description = data['description']
    if key == 'operatingsystem_support':
      data_LIST = data['operatingsystem_support']
      data_os_support = ''
      if data_LIST:
        for arr in data_LIST:
          data_os_support += "(%s %s) " % (arr['operatingsystem'], arr['operatingsystemrelease'])
          #print " %s %s" % (arr['operatingsystem'], arr['operatingsystemrelease'])
    if key == 'requirements':
      data_LIST = data['requirements']
      data_requirements = ''
      if data_LIST:
        for arr in data_LIST:
          data_requirements += "(%s %s) " % (arr['name'], arr['version_requirement'])
    if key == 'dependencies':
      data_LIST = data['dependencies']
      data_dependencies = ''
      if data_LIST:
        for arr in data_LIST:
          data_dependencies += "(%s %s) " % (arr['name'], arr['version_requirement'])

##################
def getModuleInfo(metafile, modname):

  global data_name, data_version, data_author, data_summary, data_license, \
    data_source, data_project_page, data_issues_url, data_description, data_os_support, \
    data_requirements, data_dependencies, data_tags

  if metafile == "NULL":
    data_name = data_version = data_author = data_summary = data_license = \
      data_source = data_project_page = data_issues_url = data_description = data_os_support = \
      data_requirements = data_dependencies = data_tags = False
    #data_name = modname
  else:
    # get & parse JSON
    data = getJson(metafile)
    parseJSON(data)


  md_table = '### MODULE-[' + modname + ']\n\n'
  #md_table += ' Module directory: ' + os.path.dirname(os.path.realpath(__file__)) + __file__ + '\n\n'
  md_table += "| METADATA       | VALUE                 |\n"
  md_table += "| -------------- | --------------------- |\n"

  # convert2table
  if modname:
    md_table += "| `ALIAS NAME`         | **%s**                |\n" % modname
  else:
    md_table += "| `ALIAS NAME`         | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_name:
    md_table += "| `NAME`         | **%s**                |\n" % data_name
  else:
    md_table += "| `NAME`         | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_version:
    md_table += "| `VERSION`      | **%s**                |\n" % data_version
  else:
    md_table += "| `VERSION`      | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_summary:
    md_table += "| `SUMMARY`      | **%s**                |\n" % data_summary
  else:
    md_table += "| `SUMMARY`      | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_description:
    md_table += "| `DESCRIPTION`  | **%s**                |\n" % data_description
  else:
    md_table += "| `DESCRIPTION`  | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_dependencies:
    md_table += "| `DEPENDENCIES` | %s                    |\n" % data_dependencies
  else:
    md_table += "| `DEPENDENCIES` | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_os_support:
    md_table += "| `OS SUPPORT`   | %s                    |\n" % data_os_support
  else:
    md_table += "| `OS SUPPORT`   | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_requirements:
    md_table += "| `REQUIREMENTS` | %s                    |\n" % data_requirements
  else:
    md_table += "| `REQUIREMENTS` | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
#  if data_tags:
#    md_table += "| `TAGS`        | **%s**                |\n" % data_tags
#  else:
#    md_table += "| `TAGS`         | `undefined or metadata.json not found` |\n"
  if data_author:
    md_table += "| `AUTHOR`       | **%s**                |\n" % data_author
  else:
    md_table += "| `AUTHOR`       | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_license:
    md_table += "| `LICENSE`      | **%s**                |\n" % data_license
  else:
    md_table += "| `LICENSE`      | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_source:
    md_table += "| `PROJECT CODE` | **%s**                |\n" % data_source
  else:
    md_table += "| `PROJECT CODE`         | `undefined`                |\n"
  if data_project_page:
    md_table += "| `PROJECT PAGE` | **%s**                |\n" % data_project_page
  else:
    md_table += "| `PROJECT PAGE` | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  if data_issues_url:
    md_table += "| `ISSUES`       | **%s**                |\n" % data_issues_url
  else:
    md_table += "| `ISSUES`       | `WARN:` _*Undefined value or `metadata.json` cannot be found*_ |\n"
  md_table += '\n'

  #print md_table
  return md_table


def main():

  global mod_wo_metadata
  OUTPUT_FILE = 'PUPPET_MODULES.md'

  if os.path.isfile(OUTPUT_FILE):
    os.remove(OUTPUT_FILE)

  md_table_head  = '## PUPPET MODULES \n\n'
  md_table_head += '> > > > NOTE: This file was created automatically by script: ' + __file__ + '\n\n'
  md_table_index = 'Table of contents: \n'
  md_table_body  = '\n'

  # Read eacho module on same dir of script

  for dir_file in os.listdir(os.path.dirname(os.path.realpath(__file__))):
    # Check if is directory
    if not os.path.isdir(dir_file):
      continue;

    mod_wo_metadata = True
    metafile = dir_file + '/metadata.json'
    initfile = dir_file + '/manifests/init.pp'

    # Check module has metadata and/or init class
    if not os.path.isfile(metafile) and not os.path.isfile(initfile):
      continue;

    elif not os.path.isfile(metafile) and os.path.isfile(initfile):
      mod_wo_metadata = True
    else:
      mod_wo_metadata = False

    md_table_index += '* [MODULE: %s](#module-%s)\n' % (dir_file, dir_file)
    # Check module metadata or warning it
    if mod_wo_metadata:
      metafile = "NULL"
      md_table_body += getModuleInfo(metafile, dir_file)
      #print " WARN - module has no metadata %s" % metafile
    else:
      #print " OK - module has metadata [%s]" % metafile
      md_table_body += getModuleInfo(metafile, dir_file)

  md_table = md_table_head
  md_table += md_table_index
  md_table += md_table_body

  # Write to file
  f = open(OUTPUT_FILE, 'w')
  f.write(md_table)


  if os.path.isfile(OUTPUT_FILE):
    print "SUCCESS - All data saved on file " + OUTPUT_FILE
  else:
   print "WARNIGN - Cannot found file " + OUTPUT_FILE


######################################
##> MAIN
main()
