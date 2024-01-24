//
// Created by alexander on 23.1.24.
//

#ifndef LEETCODE_SRC_6_SET_MISMATCH_H_
#define LEETCODE_SRC_6_SET_MISMATCH_H_

#include <vector>
#include <iostream>

class Solution {
 public:
  std::vector<int> findErrorNums(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    if (nums.empty()) {
      return {};
    }

    if (nums.size() == 1) {
      return {};
    }

    std::vector<int> result = {0, 0};
    int counter = 0;

    for (size_t i = 0, j = 1; j < nums.size() && counter != 2; ++i, ++j) {
      if (nums[i] == nums[j]) {
        result[0] = nums[i];
        ++counter;
      } else if (nums[i] + 1 != nums[j]) {
        result[1] = nums[i] + 1;
        ++counter;
      }
    }

    if (counter == 1) {
      if (nums[0] > 1) {
        result[1] = nums[0] - 1;
      } else {
        result[1] = nums[nums.size() - 1] + 1;
      }
    }

    return result;
  }
};

#endif //LEETCODE_SRC_6_SET_MISMATCH_H_
