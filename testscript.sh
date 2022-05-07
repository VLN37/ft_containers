#!/bin/bash

make test

time ./accft > ft
time ./accstd > std
diff --color -y -s --suppress-common-lines std ft

rm ft std accft accstd
