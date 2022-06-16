//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 16/06/2022

#include "containers.hpp"
#include "gtest.h"

TEST(containers, test1) {
  EXPECT_EQ(0, 0);
}
TEST(containers, test2) {
  EXPECT_EQ(1, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
