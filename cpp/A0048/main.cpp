// URL    : https://leetcode-cn.com/problems/rotate-image/
// Author : Modnar
// Date   : 2020/03/09

#include <bits/stdc++.h>

void print(const std::vector<std::vector<int>> &);
/* ************************* */

/**
 * 直接操作数组下标
 */
// Complexity: Time: O(n^2)  Space: O(1)
// Time: 4ms(78.05%)  Memory: 9.5MB(5.49%)
class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int len = matrix.size();
        for (int i = 0; i < len/2; ++i) {
            for (int j = i; j != len-i-1; ++j) {
                /* 逆时针 */
                // int temp = matrix[i][j];
                // matrix[i][j] = matrix[j][len-1-i];
                // matrix[j][len-1-i] = matrix[len-1-i][len-1-j];
                // matrix[len-1-i][len-1-j] = matrix[len-1-j][i];
                // matrix[len-1-j][i] = temp;
                /* 顺时针 */
                int temp = matrix[i][j];                        // 左上角
                matrix[i][j] = matrix[len-1-j][i];              // 左下角
                matrix[len-1-j][i] = matrix[len-1-i][len-1-j];  // 右下角
                matrix[len-1-i][len-1-j] = matrix[j][len-1-i];  // 右上角
                matrix[j][len-1-i] = temp;
            }
        }
    }
};

/* ************************* */

void print(const std::vector<std::vector<int>> &nums) {
    for (const auto &row : nums) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}

int main(int argc, const char *argv[]) {
    Solution *ans = new Solution();
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ans->rotate(matrix);
    print(matrix);
    // Ans: 7 4 1
    //      8 5 2
    //      9 6 3
    matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    ans->rotate(matrix);
    print(matrix);
    // Ans: 15 13  2  5
    //      14  3  4  1
    //      12  6  8  9
    //      16  7 10 11
    matrix = {{0, 1}, {1, 0}};
    ans->rotate(matrix);
    print(matrix);
    // Ans: 1 0
    //      0 1
    matrix = {{1}};
    ans->rotate(matrix);
    print(matrix);
    // Ans: 1
    return EXIT_SUCCESS;
}
