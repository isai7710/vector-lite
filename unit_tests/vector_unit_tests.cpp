#include <Vector.hpp>
#include <gtest/gtest.h>

class PreBuiltVector : public testing::Test {
protected:
  // This is the vector instance that will be used in the tests
  Vector vec;

  // Constructor for the test fixture
  PreBuiltVector() : vec(4) {}

  // Destructor for the test fixture with override if necessary to override in
  // future
  ~PreBuiltVector() override {}
};

TEST_F(PreBuiltVector, GivenAPreBuiltVector_WhenCheckingSize_) {
  EXPECT_EQ(vec.size(), 4);
}

