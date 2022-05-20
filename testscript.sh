#!/bin/bash

make test

echo "###################### VECTOR ACCURACY TEST #############################"

echo ""
./vector_acc_ft > ft
./vector_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

echo "##################### VECTOR PERFORMANCE TEST ###########################"

echo ""
echo -e "ft"
time ./vector_perf_ft
echo ""
echo -e "std"
time ./vector_perf_std
echo ""

echo "######################## MAP ACCURACY TEST ##############################"

echo ""
./stack_acc_ft > ft
./stack_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

# echo "####################### MAP PERFORMANCE TEST ############################"

# echo ""
# echo -e "ft"
# time ./stack_perf_ft
# echo ""
# echo -e "std"
# time ./stack_perf_std
# echo ""

# echo "######################## SET ACCURACY TEST ##############################"

# echo ""
# ./stack_acc_ft > ft
# ./stack_acc_std > std
# diff --color -y -s --suppress-common-lines std ft
# echo ""

# echo "####################### SET PERFORMANCE TEST ############################"

# echo ""
# echo -e "ft"
# time ./stack_perf_ft
# echo ""
# echo -e "std"
# time ./stack_perf_std
# echo ""

echo "####################### STACK ACCURACY TEST #############################"

echo ""
./stack_acc_ft > ft
./stack_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

echo "###################### STACK PERFORMANCE TEST ###########################"

echo ""
echo -e "ft"
time ./stack_perf_ft
echo ""
echo -e "std"
time ./stack_perf_std
echo ""

rm ft std
