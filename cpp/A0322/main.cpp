// URL    : https://leetcode-cn.com/problems/coin-change/
// Author : Modnar
// Date   : 2020/03/08
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Complexity: Time: O(Sn)  Space: O(S)  S为价格总值, n为货币面额种数
// Time: 64ms(58.43%)  Memory: 16.6MB(10.25%)
class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        int Max = amount + 1;
        std::vector<int> dp(amount+1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
            for (int j = 0; j != coins.size(); ++j)
                if (coins[j] <= i)
                    dp[i] = std::min(dp[i], dp[i-coins[j]]+1);
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> coins = {1, 2, 5};
    std::cout << (new Solution())->coinChange(coins, 11) << std::endl;
    // Ans: 3
    coins = {2};
    std::cout << (new Solution())->coinChange(coins, 3) << std::endl;
    // Ans: -1
    coins = {186, 419, 83, 408};
    std::cout << (new Solution())->coinChange(coins, 6249) << std::endl;
    // Ans: 20
    return EXIT_SUCCESS;
}
