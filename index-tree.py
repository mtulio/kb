#import os
#import shlex, subprocess

#dir = './'
#while trigger is true:
    #cmd = 'ls ' + dir
    #print cmd
#ret = os.system(cmd)
#print ret


#dir = './'
#cmd = 'ls ' + dir
#dirlist = os.system(cmd)
#args = shlex.split(cmd)
#dirlist = subprocess.Popen(args)
#print dirlist.readline()
#print "==="
#print dirlist.split()

#dirvect = dirlist.split()
#for item in dirvect:
    #print item


########### OK:
import os
URL_BASE = 'https://github.com/mtulio/kb/tree/master'

BODY = []
BODY.append("Project INDICE<br>")
#BODY = "# Project INDICE\\n"

def list_files(startpath):
    for root, dirs, files in os.walk(startpath):
        if './.git' in root:
            continue
        #print "root=[%s] dirs=[%s] files=[%s]" % (root, dirs, files)
        level = root.replace(startpath, '').count(os.sep)
        indent = '-' * 4 * (level)
        URL = "%s/%s" % (URL_BASE, os.path.basename(root))
        URL_MD = "[%s](%s)<br>" % (os.path.basename(root), URL)
        #print('{}{}/'.format(indent, os.path.basename(root)))
        print('{}{}/'.format(indent, URL_MD))
        BODY.append(URL_MD)
        subindent = '-' * 4 * (level + 1)
        for f in files:
            URL = "%s/%s" % (URL_BASE, f)
            URL_MD = "[%s](%s)<br>" % (f, URL)
            #print('{}{}'.format(subindent, f))
            print('{}{}'.format(subindent, URL_MD))
            BODY.append(URL_MD)

startpath = './'
list_files(startpath)

##########################################
ret_str = os.system('tree')

print "------"
import subprocess
import re
ret_str = subprocess.check_output(['tree'])
str_parent = '/'
count = 0
for line in ret_str.splitlines():
    #print '1> [' + line + ']'
    #line_name = line.split('\xe2\x94\x80 ')
    #pprint str_name
    #for str_name_2 in str_name:
    #    print '2>' + str_name_2
    #print re.findall(r"[*\ ]", line)
    for line_arr in line.split('\xe2\x94\x80 '):
        #print line_arr
        if '.' in line_arr:
            line_arr_sep = '/'
            line_arr_name = URL_BASE
            continue
        if '\xe2\x94\x80' in line_arr:
            line_arr_sep = line_arr
        else:
            line_arr_name = line_arr
            #print '2> [' + line_arr + ']'

    print "[%s](%s)" % (line_arr_sep, line_arr_name)

    count+=1
    if count == 2:
        break



#print '[\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80]'
#print '[\xe2\x94\x80]'
