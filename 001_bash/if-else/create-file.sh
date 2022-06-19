#!/bin/bash

if [ ! -e files/test.txt  ]
then
    echo "file not exist"
    touch > files/test.txt
    echo "file is created"
else
    echo "file exist"
    > files/test.txt
fi

for (( a=0; a<100 ; a++ ))
do
    printf "{$a}" >> files/test.txt;
    date >> files/test.txt;
done
echo date time is printed
