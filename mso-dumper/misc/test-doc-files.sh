#!/bin/sh

# Simple script to stress-test the doc dumper. If you want to get lots of .doc
# files, use
# http://cgit.freedesktop.org/libreoffice/core/tree/bin/get-bugzilla-attachments-by-mimetype

for i in test/doc/bugzilla/*.doc
do
	if ! ./doc-dump.py $i &> out.xml; then
		echo $i
		break
	else
		echo "$i ok"
	fi
done
