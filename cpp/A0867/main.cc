// URL    : https://leetcode-cn.com/problems/transpose-matrix/
// Author : Modnar
// Date   : 2021/02/26

#include <bits/stdc++.h>

/* ************************* */

// Time: 24ms Memory: 5.1MB
class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (const auto &vec : (new Solution())->transpose(matrix)) {
        for (const auto &val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    matrix = {
        {1, 2, 3},
        {4, 5, 6},
    };
    for (const auto &vec : (new Solution())->transpose(matrix)) {
        for (const auto &val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
