#!/bin/bash

make test

# echo "###################### VECTOR ACCURACY TEST #############################"

# echo ft
#./vector_acc_ft > ft
# echo std
#./vector_acc_std > std
# diff --color -y -s --suppress-common-lines std ft

# echo "##################### VECTOR PERFORMANCE TEST ###########################"
# time ./vector_perf_ft
# time ./vector_perf_std

echo "####################### STACK ACCURACY TEST #############################"

# echo ft
./stack_acc_ft > ft
# echo std
./stack_acc_std > std
diff --color -y -s --suppress-common-lines std ft

echo "###################### STACK PERFORMANCE TEST ###########################"
echo ft
time ./stack_perf_ft
echo std
time ./stack_perf_std

rm ft std
