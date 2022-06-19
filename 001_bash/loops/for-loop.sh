#!/bin/bash

argc=$#
argv=$@

# this will print args
for a
do
    # printf "%s\n" "$a"
    echo $a
done

printf "argc:%s  \nargv:%s\n" "$argc" "$argv"

# for i in $(seq 5)
# for i in {1..5}
for ((i=1;i<=5;i++))
do
    # echo -n $i
    printf "$i"
done
echo
for ((i=1;i<=3;i++))
{
    # echo -n $i
    printf "$i"
}
exit 0