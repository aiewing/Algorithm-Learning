#include "gtest/gtest.h"

#include "Solution.h"

class MyTest : public ::testing::Test {
public:
    Solution s;

    MyTest() {
      // initialization code here
      s = Solution();
    }

    void SetUp() {
      // code here will execute just before the test ensues
    }

    void TearDown() {
      // code here will be called just after the test completes
      // ok to through exceptions from here if need be
    }

    ~MyTest() {
      // cleanup any pending stuff, but no exceptions allowed
    }
};

TEST_F(MyTest, test1) {
  ASSERT_EQ(1, true);
};


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}