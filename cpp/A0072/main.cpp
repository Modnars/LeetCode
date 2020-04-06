// URL    : https://leetcode-cn.com/problems/edit-distance/
// Author : Modnar
// Date   : 2020/04/06

#include <bits/stdc++.h>

/* ************************* */

using std::string;
using std::vector;

// Time: 20ms(40.90%)  Memory: 9.2MB(90.54%)
class Solution {
public:
    int minDistance(const string &word1, const string &word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i)
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        return dp[word1.size()][word2.size()];
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->minDistance("abc", "") << std::endl;
    // Ans: 3
    std::cout << (new Solution())->minDistance("horse", "ros") << std::endl;
    // Ans: 3
    std::cout << (new Solution())->minDistance("intention", "execution") << std::endl;
    // Ans: 5
    return EXIT_SUCCESS;
}
