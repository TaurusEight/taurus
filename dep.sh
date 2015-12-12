#!/bin/bash

dep=${1%.*}.d
g++ -std=c++11 -c -MM -MF ${dep} $1
echo -e "\tg++ -std=c++11 -c -o \$@ \$<" >> ${dep}
