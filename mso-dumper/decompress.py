#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys, os.path, optparse

from msodumper import vbahelper

def main():

    offset = 0
    if len ( sys.argv ) > 1:
        offset = int(sys.argv[1])

    chars = sys.stdin.read()

    compressed = vbahelper.CompressedVBAStream( chars, offset )
    decompressed = compressed.decompress()
    sys.stdout.write(decompressed)

    exit(0)

if __name__ == '__main__':
    main()

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:
