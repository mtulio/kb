import os
from os.path import join, getsize
import re

# TODO:
#> Remove duplicate print dirs
#> Print tree, altrough all_dir and tree

def index_files(filepath):
    for root, dirs, files in os.walk(filepath):
        if re.search(r'\.git', root, re.M|re.I):
            continue

        for _dir in dirs:
            if re.search(r'\.git', _dir, re.M|re.I):
                continue
            print '_d=[%s/%s]' % (root, _dir)
            index_files(_dir)

        for _file in files:
            print '_f=[%s]: [%s]' % (root, _file)

index_files('./')
