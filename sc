#!/bin/sh
# remove files with name pattern matching regular expression

echo -n "Enter directories: "
read dirs

echo -n "Enter filename regular expression: "
read pattern

find $dirs > /tmp/result
#cat /tmp/result
cmd='rm -i  `grep '$pattern' /tmp/result`'
echo "Running command $cmd"
eval $cmd

rm /tmp/result
