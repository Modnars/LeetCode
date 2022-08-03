// File:   A0001/main.cc
// Author: modnarshen
// Date:   2022.08.03

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target) {
        std::unordered_map<int, int> index;
        std::vector<int> ans;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            auto iter = index.find(nums[i]);
            if (iter != index.end()) {
                ans.emplace_back(iter->second);
                ans.emplace_back(i);
                break;
            } else {
                index[target - nums[i]] = i;
            }
        }
        return ans;
    }
};

void printVec(const std::vector<int> &nums) {
    for (const auto &v : nums)
        std::cout << v << " ";
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    auto solution = new Solution();
    printVec(solution->twoSum({2, 7, 11, 15}, 9)); // 0 1
    printVec(solution->twoSum({3, 2, 4}, 6));      // 1 2
    printVec(solution->twoSum({3, 3}, 6));         // 0 1
    return 0;
}
