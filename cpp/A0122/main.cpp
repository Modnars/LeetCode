// URL    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Modnar
// Date   : 2020/02/25

#include <bits/stdc++.h>

/* ************************* */

// Time: 8ms(71.86%)  Memory: 15.1MB(5.07%)
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() == 0) return 0;
        int profit = 0;
        for (int i = 0; i != prices.size()-1; ++i) {
            if (prices[i] < prices[i+1])
                profit += prices[i+1] - prices[i];
        }
        return profit;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << (new Solution())->maxProfit(prices) << std::endl;
    // Ans: 7
    prices = {1, 2, 3, 4, 5};
    std::cout << (new Solution())->maxProfit(prices) << std::endl;
    // Ans: 4
    prices = {7, 6, 4, 3, 1};
    std::cout << (new Solution())->maxProfit(prices) << std::endl;
    // Ans: 0
    prices = {};
    std::cout << (new Solution())->maxProfit(prices) << std::endl;
    // Ans: 0
    return EXIT_SUCCESS;
}
