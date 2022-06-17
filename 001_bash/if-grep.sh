#!/bin/bash

arg1=$1
arg2=$2

# if grep -q Bash    file ;then
if grep   -q  $arg1  $arg2 ;then
    echo "file contains at least once in $arg2" ;
else
    echo "not mentioned"
fi