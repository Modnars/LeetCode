// URL    : https://leetcode-cn.com/problems/rotate-matrix-lcci/
// Author : Modnar
// Date   : 2020/04/07
// SameTo : A0048

#include <bits/stdc++.h>

/* ************************* */

// Time: 0ms(100.00%)  Memory: 7.1MB(100.00%)
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

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
