#!/bin/bash
# Execute this in the parent directory of the 'mso-dumper' directory.

VER=0.2
DESTDIR=mso-dumper-$VER
mkdir -p $DESTDIR/src
cp mso-dumper/*.py $DESTDIR/
cp mso-dumper/src/*.py $DESTDIR/src/
tar cvf $DESTDIR.tar.gz $DESTDIR
rm -rf $DESTDIR

