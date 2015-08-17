#!/usr/bin/python

import subprocess
import sys

if len(sys.argv) != 2:
    print 'Usage: python main.py <PPT file>'
    sys.exit(-1)

ppt = str(sys.argv[1])

subprocess.call(['java', '-jar', 'PPTHandler.jar', ppt])