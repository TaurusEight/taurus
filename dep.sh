#!/bin/bash

dep=${1%.*}.d
obj=${1%.*}.o
g++ -std=c++11 -c -MM -MF ${dep} $1
echo -e "\tg++ -std=c++11 -c -o ${obj} \$<" >> ${dep}
