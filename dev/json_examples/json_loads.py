#! /usr/bin/python

import json

student_json = '''[{"isStudent": true,
				"courses": {"major": "Finance", "minor": "Marketing"}, 
				"scores": [10, 20, 30, 40], "id": 101, 
				"name": "John Doe"}]'''

print json.loads(student_json);
