#! /bin/sh

test_dir=$1

if [ ! -d $test_dir ]
then
    echo "Usage: test-files.sh TEST_DIR"
    exit 1
fi

for x in `find $test_dir -name \*.xls`; do
    touch tmp
    python xls-dump.py $x > tmp
    ret_val=$?
    if [ $ret_val -eq 0 ]
    then
        grep "rror inter" tmp > /dev/null
        if [ $? -eq 0 ]
        then
            echo "Flat dump failed for" $x "- failure in xlsrecord parse"
        fi
    else
        echo "Flat dump failed for" $x "- unrecognised failure"
    fi
    
    rm tmp
    python xls-dump.py --dump-mode=xml $x > /dev/null || echo "Xml dump failed for" $x
    python xls-dump.py --dump-mode=cxml $x > /dev/null || echo "CXml dump failed for" $x
done
