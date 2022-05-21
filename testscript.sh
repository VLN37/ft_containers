#!/bin/bash

make test

echo "VECTOR MEMORY TEST ######################################################"

echo ""
valgrind ./vector/vector_test | grep -i '=='
echo ""

echo "VECTOR ACCURACY TEST ####################################################"

echo ""
./vector/vector_acc_ft > ft
./vector/vector_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

echo "VECTOR PERFORMANCE TEST #################################################"

echo ""
echo -e -n "ft"
time ./vector/vector_perf_ft
echo ""
echo -e -n "std"
time ./vector/vector_perf_std
echo ""

echo "MAP MEMORY TEST #########################################################"

echo ""
valgrind ./map/map_test | grep -i '=='
echo ""

echo "MAP ACCURACY TEST #######################################################"

echo ""
./map/map_acc_ft > ft
./map/map_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

echo "MAP PERFORMANCE TEST ####################################################"

echo ""
echo -e -n "ft"
time ./map/map_perf_ft
echo ""
echo -e -n "std"
time ./map/map_perf_std
echo ""

echo "SET MEMORY TEST #########################################################"

echo ""
valgrind ./set/set_test | grep -i '=='
echo ""

echo "SET ACCURACY TEST #######################################################"

echo ""
./set/set_acc_ft > ft
./set/set_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

echo "SET PERFORMANCE TEST ####################################################"

echo ""
echo -e -n "ft"
time ./set/set_perf_ft
echo ""
echo -e -n "std"
time ./set/set_perf_std
echo ""

echo "SET MEMORY TEST #########################################################"

echo ""
valgrind ./stack/stack_test | grep -i '=='
echo ""

echo "STACK ACCURACY TEST #####################################################"

echo ""
./stack/stack_acc_ft > ft
./stack/stack_acc_std > std
diff --color -y -s --suppress-common-lines std ft
echo ""

echo "STACK PERFORMANCE TEST ##################################################"

echo ""
echo -e -n "ft"
time ./stack/stack_perf_ft
echo ""
echo -e -n "std"
time ./stack/stack_perf_std
echo ""

rm ft std
