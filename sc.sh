#!/bin/sh
# remove files with name pattern matching regexp
[ x$1 = x ] && { echo -n "Enter directory: "; read dir } || dir=$1
[ x$2 = x ] && { echo -n "Enter pattern: "; read pat } || pat=$1
find $dir > /tmp/listing
cmd=’rm ‘grep ’$pat’ /tmp/listing‘’
echo "Running command $cmd"; eval $cmd
