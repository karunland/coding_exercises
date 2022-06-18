#!/bin/sh
echo ./zmore file

E_NOARGS=85
E_NOTFOUND=86
E_NOGZIP=87

filename=$1

if [ -z "$filename" ] # [ $# -eq 0 ] # is same
then
    echo "Wrong usage. Must be arg1"
fi

if [ ${filename##*.} != "gz" ]
# Using bracket in variable substitution.
then
    echo "File $1 is not a gzipped file!"
    exit $E_NOTGZIP
fi

zcat $1 | more
