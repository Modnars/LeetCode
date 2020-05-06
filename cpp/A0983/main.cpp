// URL    : https://leetcode-cn.com/problems/minimum-cost-for-tickets/
// Author : Modnar
// Date   : 2020/05/06
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/minimum-cost-for-tickets/solution/zui-di-piao-jie-by-leetcode-solution/
// Time: 8ms(44.12%)  Memory: 9.9MB(20.00%)
class Solution {
private:
    std::vector<int> days, costs;
    std::vector<int> memo;
    int durations[3] = {1, 7, 30};
    
public:
    int mincostTickets(std::vector<int> &days, std::vector<int> &costs) {
        this->days = days;
        this->costs = costs;
        memo.assign(days.size(), -1);
        return dp(0);
    }

    int dp(int i) {
        if (i >= days.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; ++k) {
            while (j < days.size() && days[j] < days[i] + durations[k]) {
                ++j;
            }
            memo[i] = std::min(memo[i], dp(j) + costs[k]);
        }
        return memo[i];
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};
    std::cout << (new Solution())->mincostTickets(days, costs) << std::endl;
    // Ans: 11
    days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31},  costs = {2, 7, 15};
    std::cout << (new Solution())->mincostTickets(days, costs) << std::endl;
    // Ans: 17
    return EXIT_SUCCESS;
}
