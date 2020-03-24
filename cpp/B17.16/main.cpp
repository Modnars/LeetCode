// URL    : https://leetcode-cn.com/problems/the-masseuse-lcci/
// Author : Modnar
// Date   : 2020/03/24
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 动态规划
 * 
 *      令dp[i]表示面对第i个预约，可以得到的最大预约时长。那么面对第i个预约，如果
 *  接受，最大收益为dp[i-2]+nums[i]; 这是因为当前预约不可与上个预约连续，且对于上上个
 *  预约，已经确定该值(dp[i-2])为最大预约时长。如果不接受，则最大收益为dp[i-1]。
 *      于是，得到动态规划转移方程：dp[i] = std::max(dp[i-1], dp[i-2]+val[i]);
 *      考虑到面对第一项预约，其最大预约时长一定是接受该预约，故dp[0] = nums[0];
 *      又考虑到便于后序转移方程处理，这里令dp下标整体向后偏移1，即第i个预约的最大预约
 *  时长就是dp[i] (1 <= i <= n)。于是对于第二个预约开始，就可以直接使用：
 *          dp[i+1] = std::max(dp[i], dp[i-1]+nums[i]); (1 <= i < nums.size())
 *      来进行状态转移计算，最后结果就是面对nums.size()个预约的最大预约时长，即
 *  dp[nums.size()]的值。
 */
// Time: 0ms(100.00%)  Memory: 7.7MB(100.00%)
class Solution {
public:
    int massage(std::vector<int> &nums) {
        if (nums.size() == 0) return 0;
        std::vector<int> dp(nums.size()+1);
        dp[1] = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            dp[i+1] = std::max(dp[i], dp[i-1]+nums[i]);
        }
        return dp[nums.size()];
    }
};

/* ************************* */

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/the-masseuse-lcci/solution/an-mo-shi-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
namespace AnsOne {
    // Time: 4ms(63.53%)  Memory: 7.7MB(100.00%)
    class Solution {
    public:
        int massage(std::vector<int> &nums) {
            int n = (int)nums.size();
            if (!n) return 0;
            int dp0 = 0, dp1 = nums[0];

            for (int i = 1; i < n; ++i){
                int tdp0 = std::max(dp0, dp1); // 计算 dp[i][0]
                int tdp1 = dp0 + nums[i]; // 计算 dp[i][1]

                dp0 = tdp0; // 用 dp[i][0] 更新 dp_0
                dp1 = tdp1; // 用 dp[i][1] 更新 dp_1
            }
            return std::max(dp0, dp1);
        }
    };
}

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << (new Solution())->massage(nums) << std::endl;
    // Ans: 4
    nums = {2, 7, 9, 3, 1};
    std::cout << (new Solution())->massage(nums) << std::endl;
    // Ans: 12
    nums = {2, 1, 4, 5, 3, 1, 1, 3};
    std::cout << (new Solution())->massage(nums) << std::endl;
    // Ans: 12
    return EXIT_SUCCESS;
}
