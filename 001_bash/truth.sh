#!/bin/bash

echo "testing the \"word\" vaiable "
word=""

if [ -n "$word" ] ; then
    echo "vairable is not empty"
else
    echo "vairable is empty"
fi


if test -n "$word"; then
    echo "vairable is not empty"
elif test -z "$word"; then
    echo "vairable is empty"
fi

if [[ -n $word ]] ; then
    echo "vairable is not empty"
else
    echo "vairable is empty"
fi

