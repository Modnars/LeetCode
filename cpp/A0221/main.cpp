// URL    : https://leetcode-cn.com/problems/maximal-square/
// Author : Modnar
// Date   : 2020/05/08
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
// Time: 20ms(70.06%)  Memory: 8.9MB(100.00%)
/**
 * 动态规划
 */
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size(), ans = 0;
        std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
        for (int i = 0; i != row; ++i) {
            for (int j = 0; j != col; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    ans = ans > dp[i][j] ? ans : dp[i][j];
                }
            }
        }
        return ans * ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    std::cout << (new Solution())->maximalSquare(matrix) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
