// URL    : https://leetcode-cn.com/problems/longest-increasing-subsequence/
// Author : Modnar
// Date   : 2020/03/14
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Failed: WRONG_ANSWER
class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        if (nums.size() == 0) return 0;
        std::vector<std::vector<int>> ans = {{nums[0]}};
        for (int i = 1; i != nums.size(); ++i) {
            bool need_append = true;
            for (int j = 0; j != ans.size(); ++j) {
                if (nums[i] > ans[j].back()) {
                    ans[j].emplace_back(nums[i]);
                    need_append = false;
                }
            }
            // ans.emplace_back({nums[i]});
            if (need_append)
                ans.emplace_back(std::vector<int>(1, nums[i]));
        }
        int maxLen = 1;
        for (const auto &row : ans) {
            for (const auto &val : row)
                std::cout << val << " ";
            std::cout << std::endl;
        }
        for (int i = 0; i != ans.size(); ++i)
            maxLen = std::max(maxLen, static_cast<int>(ans[i].size()));
        return maxLen;
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
    // Complexity: Time: O(n^2)  Space: O(n)
    // Time: 52ms(53.23%)  Memory: 9.1MB(5.18%)
    class Solution {
    public:
        int lengthOfLIS(std::vector<int> &nums) {
            int len = nums.size();
            if (len == 0) return 0;
            std::vector<int> dp(len, 1);
            for (int i = 0; i != len; ++i)
                for (int j = 0; j != i; ++j)
                    if (nums[i] > nums[j])
                        dp[i] = std::max(dp[i], dp[j]+1);
            return *std::max_element(dp.begin(), dp.end());
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << solution->lengthOfLIS(nums) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
