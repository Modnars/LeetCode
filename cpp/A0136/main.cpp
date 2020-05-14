// URL    : https://leetcode-cn.com/problems/single-number/
// Author : Modnar
// Date   : 2020/02/25

// ✅ : 2020/05/14

#include <bits/stdc++.h>

/* ************************* */

/**
 * 位运算
 */
// Time: 20ms(40.04%)  Memory: 13.9MB(5.10%)
class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        int ans = 0;
        for (const int &val : nums)
            ans ^= val;
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {2, 2, 1};
    std::cout << (new Solution())->singleNumber(nums) << std::endl;
    // Ans: 1
    nums = {4, 1, 2, 1, 2};
    std::cout << (new Solution())->singleNumber(nums) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
