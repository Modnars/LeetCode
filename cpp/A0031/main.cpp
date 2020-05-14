// URL    : https://leetcode-cn.com/problems/next-permutation/
// Author : Modnar
// Date   : 2020/05/14

#include <bits/stdc++.h>

/* ************************* */

/**
 * STL
 */
// Time: 8ms(35.85%)  Memory: 12.2MB(6.67%)
class Solution {
public:
    void nextPermutation(std::vector<int> &nums) {
        if (!std::next_permutation(nums.begin(), nums.end())) {
            std::sort(nums.begin(), nums.end());
        }
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    std::vector<int> nums = {1, 2, 3};
    solution->nextPermutation(nums);
    for (const auto &val : nums)
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 3, 2]
    nums = {3, 2, 1};
    solution->nextPermutation(nums);
    for (const auto &val : nums)
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3]
    nums = {1, 1, 5};
    solution->nextPermutation(nums);
    for (const auto &val : nums)
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 5, 1]
    return EXIT_SUCCESS;
}
