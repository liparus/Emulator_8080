#! /bin/bash

# Compile C-program using gcc

FILE=$1
OFILE=${1%.*}

gcc -C $FILE
gcc -Wall -g3 $FILE -o $OFILE

exit 0
