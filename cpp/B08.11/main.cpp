// URL    : https://leetcode-cn.com/problems/coin-lcci/
// Author : Modnar
// Date   : 2020/04/23
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/coin-lcci/solution/ying-bi-by-leetcode-solution/
// Time: 80ms(49.68%)  Memory: 14.5MB(100.00%)
class Solution {
private:
    static const int mod;
    static const std::vector<int> coins;

public:
    int waysToChange(int n) {
        std::vector<int> dp(n+1);
        dp[0] = 1;
        for (int c = 0; c != 4; ++c) {
            int coin = coins[c];
            for (int i = coin; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i-coin]) % mod;
            }
        }
        return dp[n];
    }
};

const int Solution::mod = 1000000007;
const std::vector<int> Solution::coins = {25, 10, 5, 1};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/coin-lcci/solution/ying-bi-by-leetcode-solution/
    // Time: 0ms(100.00%)  Memory: 6.1MB(100.00%)
    class Solution {
    private:
        static const int mod;

    public:
        int waysToChange(int n) {
            int ans = 0;
            for (int i = 0; i * 25 <= n; ++i) {
                int rest = n - i * 25;
                int a = rest / 10;
                int b = rest % 10 / 5;
                ans = (ans + (long long)(a + 1) * (a + b + 1) % mod) % mod;
            }
            return ans;
        }
    };

    const int Solution::mod = 1000000007;
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << (new Solution())->waysToChange(5) << std::endl;
    // Ans: 2
    std::cout << (new Solution())->waysToChange(10) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
