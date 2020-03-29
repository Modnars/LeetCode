// URL    : https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/* ************************* */

// Time: 40ms(19.03%)  Memory: 18.8MB(100.00%)
class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        int ans = 0, count = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (count == 0)
                ans = nums[i];
            if (nums[i] != ans)
                --count;
            else
                ++count;
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    std::cout << (new Solution())->majorityElement(nums) << std::endl;
    // Ans: 2
    nums = {3, 3, 4};
    std::cout << (new Solution())->majorityElement(nums) << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
