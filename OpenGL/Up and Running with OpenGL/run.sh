#!/bin/bash
#calls cd build 
#cmake .. -DSRC<argument> && make argument

EMBEDDED=`echo $2`
DIRECTORY=`echo $1 |cut -d'/' -f1`
FILENAME=`echo $1 |cut -d'/' -f2 |cut -d'.' -f1 | sed -e "s|/|_|g"`
TARGET=${FILENAME}

mkdir build
cd build
rm bin/${TARGET}
cmake .. -DSRC=../$1
make VERBOSE=1
bin/${TARGET}

