#! /usr/bin/python

import json

student = [{'id':101, 'name':'John Doe', 'isStudent':True, 
			'scores':(10, 20, 30, 40), 
			'courses':{'major':'Finance', 'minor':'Marketing'}
			}]

print json.dumps(student)
