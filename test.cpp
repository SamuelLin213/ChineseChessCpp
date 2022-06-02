#include "gtest/gtest.h"

#include "generalMove_test.h"
#include "advisorMove_test.h"
#include "elephantMove_test.h"
#include "soldierMove_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
