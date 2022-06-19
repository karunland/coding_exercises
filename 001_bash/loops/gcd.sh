#!/bin/bash
# Argument check
ARGS=2
E_BADARGS=85
if [ $# -ne "$ARGS" ]
then
    echo "Usage: `basename $0` first-number second-number"
    exit $E_BADARGS
fi
# ------------------------------------------------------
gcd ()
{
    dividend=$1 # Arbitrary assignment.
    divisor=$2 #! It doesn't matter which of the two is larger.
    # Why not?
    remainder=1 # If a+_n uninitialized variable is used inside
    #+ test brackets, an error message results.
    until [ "$remainder" -eq 0 ]
    do # ^^^^^^^^^^ Must be previously initialized!
        let "remainder = $dividend % $divisor"
        dividend=$divisor # Now repeat with 2 smallest numbers.
        divisor=$remainder
    done # Euclid's algorithm
} # Last $dividend is the gcd.
echo  $dividend $divisor