// URL    : https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
// Author : Modnar
// Date   : 2020/03/28

#include <bits/stdc++.h>

/* ************************* */

/**
 * 双指针
 */
// Time: 48ms(9.16%)  Memory: 18MB(100.00%)
class Solution {
public:
    std::vector<int> exchange(std::vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < nums.size() && nums[l] & 1) ++l;
            while (r >= 0 && nums[r] % 2 == 0) --r;
            if (l < r) std::swap(nums[l], nums[r]);
        }
        return nums;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3, 4};
    for (const int &val : (new Solution())->exchange(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    nums = {};
    for (const int &val : (new Solution())->exchange(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    nums = {1, 3, 5};
    for (const int &val : (new Solution())->exchange(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
