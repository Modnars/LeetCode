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

/**
 * 动态规划
 *     维护dp数组记录nums中位置为i处的最长上升子序列长度。对于dp数组中元素来说，初始值
 * 为1，对于0到i-1中的位置j，若满足nums[i]>nums[j]，则更新dp[i] = max(dp[i], dp[j]+1);
 * 最后，选出dp中最大的元素，即为得到的整个数组的最长上升子序列的长度。
 */
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

/**
 * 贪心+二分搜索
 *     维护一个有序数组d，当遍历到nums[i]时，若nums[i]比d的最后一个元素大时，直接将
 * nums[i]添加到d尾端；否则寻找d中nums[i]能够插入的位置，并将其替换d中某原有元素。
 * 这样，遍历一遍nums，同时针对有序数组d采取二分查找，综合复杂度为O(n*logn)。
 */
namespace AnsTwo {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 4ms(94.16%)  Memory: 9.2MB(5.07%)
    class Solution {
    public:
        int lengthOfLIS(std::vector<int> &nums) {
            int len = 1, n = nums.size();
            if (n == 0) return 0;
            std::vector<int> d(n+1, 0);
            d[len] = nums[0];
            for (int i = 1; i != n; ++i) {
                if (nums[i] > d[len]) {
                    d[++len] = nums[i];
                } else {
                    int l = 1, r = len, pos = 0;
                    // 如果找不到说明所有的数都比nums[i]大，此时要更新d[1]，
                    // 所以这里将pos设为0
                    while (l <= r) {
                        int mid = (l + r) >> 1;
                        if (d[mid] < nums[i]) {
                            pos = mid;
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    d[pos+1] = nums[i];
                } // if-else
            } // for
            return len;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    Solution *solution = new Solution();
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << solution->lengthOfLIS(nums) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
