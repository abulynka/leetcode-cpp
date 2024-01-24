#include "gtest/gtest.h"
#include <vector>

#include "_6/645_set_mismatch.h"

TEST(_645, set_mismatch) {
  Solution solution;

  // examples from leetcode
  EXPECT_EQ(solution.findErrorNums({1,2,2,4}), std::vector<int>({2, 3}));
  EXPECT_EQ(solution.findErrorNums({1,1}), std::vector<int>({1, 2}));

  // Minimum Input
  EXPECT_EQ(solution.findErrorNums({2, 2}), std::vector<int>({2, 1}));

  // Maximum Input
  std::vector<int> maxInput;
  for (int i = 1; i <= 104; ++i) {
    maxInput.push_back(i);
  }
  maxInput.push_back(2);
  EXPECT_EQ(solution.findErrorNums(maxInput), std::vector<int>({2, 105}));

  // Two Duplicates at the Beginning
  EXPECT_EQ(solution.findErrorNums({2, 2, 3, 4}), std::vector<int>({2, 1}));

  // Two Duplicates at the End
  EXPECT_EQ(solution.findErrorNums({1, 2, 3, 4, 4}), std::vector<int>({4, 5}));

  // Duplicates in the Middle
  EXPECT_EQ(solution.findErrorNums({1, 2, 3, 3, 4}), std::vector<int>({3, 5}));

  // Random Duplicates
  EXPECT_EQ(solution.findErrorNums({4, 2, 1, 4, 3}), std::vector<int>({4, 5}));
}
