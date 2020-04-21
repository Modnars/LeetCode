// URL    : https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
// Author : Modnar
// Date   : 2020/04/21
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Time: 276ms(56.21%)  Memory: 65.9MB(100.00%)
class Solution {
public:
    int numberOfSubarrays(std::vector<int> &nums, int k) {
        int len = nums.size(), ans = 0, count = 0;
        std::vector<int> odd(len+2);
        for (int i = 0; i != len; ++i) {
            if (nums[i] & 1)
                odd[++count] = i;
        }
        odd[0] = -1, odd[++count] = len;
        for (int i = 1; i+k <= count; ++i) {
            ans += (odd[i] - odd[i-1]) * (odd[i+k] - odd[i+k-1]);
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 1, 2, 1, 1};
    std::cout << (new Solution())->numberOfSubarrays(nums, 3) << std::endl;
    // Ans: 2
    nums = {2, 4, 6};
    std::cout << (new Solution())->numberOfSubarrays(nums, 1) << std::endl;
    // Ans: 0
    nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    std::cout << (new Solution())->numberOfSubarrays(nums, 2) << std::endl;
    // Ans: 16
    return EXIT_SUCCESS;
}
