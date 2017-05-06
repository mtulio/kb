import os
import subprocess
import re

URL_BASE = 'https://github.com/mtulio/kb/tree/master'
BODY = []
BODY.append("Project INDICE<br>")

ret_str = subprocess.check_output(['tree'])
str_parent = '/'
count = tree_end = 0
for line in ret_str.splitlines():
    #print '\n1> [' + line + ']'
    line_name = line.split('\xe2\x94\x80 ')
    #print '\n2> [' + repr(line_name) +']'
    #pprint str_name
    #for str_name_2 in str_name:
    #    print '2>' + str_name_2
    #print re.findall(r"[*\ ]", line)
    for line_arr in line.split('\xe2\x94\x80 '):
        #print line_arr
        # Get root
        if len(line_arr) == 0:
            tree_end = 1
            continue;
        if tree_end == 1:
            str_resume = line;
            continue;

        if len(line_arr) > 0 and '.' in line_arr[0]:
            line_arr_sep = '/'
            line_arr_name = ''
            continue
        #print '\n3> [' + repr(line_arr) +']'
        # Get parent
        if '\xe2\x94\x80' in line_arr:
            line_arr_sep = line_arr
        else:
            line_arr_name = line_arr
            #print '2> [' + line_arr_name + ']'
            URL = URL_BASE + '/' + line_arr_name
            #MSG = '[' + line_arr_sep +' '+ line_arr_name + '](' + URL + ')<br>'
            MSG = "[%s %s](%s)<br>" % (line_arr_sep, line_arr_name, URL)
            print "[%s %s](%s)<br>" % (line_arr_sep, line_arr_name, URL)
            #print MSG
            #print MSG
            BODY.append(MSG)



    count+=1
    #if count == 20:
    #    break

BODY.append(str_resume)
#print BODY
