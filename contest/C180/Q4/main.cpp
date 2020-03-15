// URL    : https://leetcode-cn.com/contest/weekly-contest-180/problems/maximum-performance-of-a-team/
// Author : Modnar
// Date   : 2020/03/15

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    int maxPerformance(int n, std::vector<int> &speed, std::vector<int> &efficiency, 
            int k) {
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(k+1));
        int sum_speed = speed[0], min_efficiency = efficiency[0];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][k-j]+);
            }
        }
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
