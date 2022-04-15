#!/bin/bash

make perfft

time ./perfft > ft
time ./perfstd > std
diff -s --color std ft

rm ft std perfft perfstd
