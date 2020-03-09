// URL    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
// Author : Modnar
// Date   : 2020/02/25

// ✅ : 2020/03/09

#include <bits/stdc++.h>

/* ************************* */

// Time: 8ms(77.75%)  Memory: 15.2MB(5.05%)
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (!prices.size()) return 0;
        int profit = 0, cost = prices[0];
        for (const int &price : prices) {
            if (price < cost)
                cost = price;
            else if (price-cost > profit)
                profit = price - cost;
        }
        return profit;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << (new Solution())->maxProfit(prices) << std::endl;
    // Ans: 5
    prices = {7, 6, 4, 3, 1};
    std::cout << (new Solution())->maxProfit(prices) << std::endl;
    // Ans: 0
    return EXIT_SUCCESS;
}
