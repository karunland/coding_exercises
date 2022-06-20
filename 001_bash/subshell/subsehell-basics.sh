#!/bin/bash

maxiteration=$1

echo "this is the parent sheel and started"
echo "-----------------------"

# blocking multiproc scripting
# (
#     for ((i = 0; i < $maxiteration; i++)); do
#         echo "$i this is the subshell"
#         sleep 1
#     done
# )

# unblocking multiproc scripting
(
    for ((i = 0; i < $maxiteration; i++)); do
        echo "$i first sub subshell"
        sleep 1
    done
    exit 0
) &

# unblocking multiproc scripting
(
    for ((i = $maxiteration; i >= 0; i--)); do
        echo "$i second sub subshell"
        sleep 1
    done
    exit 0
) &

sleep 1

echo "this is the parent sheel and ended"
