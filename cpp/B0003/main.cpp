// URL    : https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
// Author : Modnar
// Date   : 2020/03/10

#include <bits/stdc++.h>

/* ************************* */

// Time: 92ms(17.22%)  Memory: 29.7MB(100.00%)
class Solution {
public:
    int findRepeatNumber(std::vector<int> &nums) {
        std::set<int> check;
        for (const int &val : nums)
            if (check.find(val) == check.end())
                check.insert(val);
            else
                return val;
        return -1;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {2, 3, 0, 1, 2, 5, 3};
    std::cout << (new Solution())->findRepeatNumber(nums) << std::endl;
    // Ans: 2 or 3
    return EXIT_SUCCESS;
}
