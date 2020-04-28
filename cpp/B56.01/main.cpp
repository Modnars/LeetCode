// URL    : https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
// Author : Modnar
// Date   : 2020/04/28

#include <bits/stdc++.h>

/* ************************* */

// Time: 44ms(44.67%)  Memory: 16.1MB(100.00%)
class Solution {
public:
    std::vector<int> singleNumbers(std::vector<int> &nums) {
        int check = 0, pos = 1;
        std::vector<int> ans(2, 0);
        for (const int &val : nums)
            check ^= val;
        while ((pos & check) == 0)
            pos = pos << 1;
        for (const int &val : nums)
            if (pos & val)
                ans[0] ^= val;
        ans[1] = check ^ ans[0];
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {4, 1, 4, 6};
    for (const auto &val : (new Solution())->singleNumbers(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: {1, 6}
    nums = {1, 2, 10, 4, 1, 4, 3, 3};
    for (const auto &val : (new Solution())->singleNumbers(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: {2, 10}
    return EXIT_SUCCESS;
}
