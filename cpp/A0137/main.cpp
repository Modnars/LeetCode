// URL    : https://leetcode-cn.com/problems/single-number-ii/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Time: 4ms(99.87%)  Memory: 11.8MB(5.40%)
class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        int seen_once = 0, seen_twice = 0;
        for (const int &val : nums) {
            seen_once = ~seen_twice & (seen_once ^ val);
            seen_twice = ~seen_once & (seen_twice ^ val);
        }
        return seen_once;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {2, 2, 3, 2};
    std::cout << (new Solution())->singleNumber(nums) << std::endl;
    // Ans: 3
    nums = {0, 1, 0, 1, 0, 1, 99};
    std::cout << (new Solution())->singleNumber(nums) << std::endl;
    // Ans: 99
    return EXIT_SUCCESS;
}
