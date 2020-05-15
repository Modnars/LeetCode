// URL    : https://leetcode-cn.com/problems/subarray-sum-equals-k/
// Author : Modnar
// Date   : 2020/05/15

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/
// Time: 68ms(68.32%)  Memory: 22MB(6.67%)
class Solution {
public:
    int subarraySum(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto & x : nums) {
            pre += x;
            if (mp.find(pre-k) != mp.end())
                count += mp[pre-k];
            ++mp[pre];
        }
        return count;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
