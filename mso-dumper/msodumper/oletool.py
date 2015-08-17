#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys, os.path, optparse
sys.path.append(sys.path[0]+"/src")

import ole, globals


def main ():
    parser = optparse.OptionParser()
    parser.add_option("-l", "--list", action="store_true", dest="list", default=False, help="lists ole contents")
    parser.add_option("-x", "--extract", action="store_true", dest="extract", default=False, help="extract file")


    options, args = parser.parse_args()

    params = globals.Params()

    params.list =  options.list
    params.extract =  options.extract

    if len(args) < 1:
        globals.error("takes at least one argument\n")
        parser.print_help()
        sys.exit(1)

    container = ole.OleContainer( args[ 0 ], params )

    if params.list == True:
        container.list()
    if params.extract:
       files = args
       files.pop(0)

       for file in files:
           container.extract( file )

if __name__ == '__main__':
    main()

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:
