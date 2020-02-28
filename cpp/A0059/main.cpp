// URL    : https://leetcode-cn.com/problems/spiral-matrix-ii/
// Author : Modnar
// Date   : 2020/02/28

#include <bits/stdc++.h>

/* ************************* */

/**
 * 思路同A0054相同
 */
// Time: 0ms(100.00%)  Memory: 9.1MB(5.89%)
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        if (n == 0) return std::vector<std::vector<int>>();
        int min_row = 0, max_row = n-1, min_col = 0, max_col = n-1, idx = 0;
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        while (min_row < max_row && min_col < max_col) {
            for (int j = min_col; j != max_col; ++j)
                matrix[min_row][j] = ++idx;
            for (int i = min_row; i != max_row; ++i)
                matrix[i][max_col] = ++idx;
            for (int j = max_col; j != min_col; --j)
                matrix[max_row][j] = ++idx;
            for (int i = max_row; i != min_row; --i)
                matrix[i][min_col] = ++idx;
            ++min_row; ++min_col;
            --max_row; --max_col;
        }
        if (n & 1)
            for (int j = min_col; j <= max_col; ++j)
                matrix[min_row][j] = ++idx;
        return matrix;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    for (const auto &row : (new Solution())->generateMatrix(3)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    for (const auto &row : (new Solution())->generateMatrix(4)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
