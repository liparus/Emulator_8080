#! /bin/bash

# Compile C-program using gcc

FILE=$1
OFILE=${1%.*}

gcc -C $FILE
gcc $FILE -o $OFILE
