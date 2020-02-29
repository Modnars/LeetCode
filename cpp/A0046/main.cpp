// URL    : https://leetcode-cn.com/problems/permutations/
// Author : Modnar
// Date   : 2020/02/29
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3};
    for (const auto &row : (new Solution())->permute(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    nums = {1};
    for (const auto &row : (new Solution())->permute(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    nums = {0, 1};
    for (const auto &row : (new Solution())->permute(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
