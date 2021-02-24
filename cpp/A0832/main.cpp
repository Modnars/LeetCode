// URL    : https://leetcode-cn.com/problems/flipping-an-image/
// Author : Modnar
// Date   : 2021/02/24

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms Memory: 8.3MB
class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &A) {
        int m = A.size();
        int n = A[0].size();
        for (int i = 0; i < m; ++i) {
            for (int l = 0, r = n - 1; l < r; ++l, --r) {
                if (A[i][l] != A[i][r]) {
                    std::swap(A[i][l], A[i][r]);
                }
                A[i][l] = !A[i][l];
                A[i][r] = !A[i][r];
            }
            if (n % 2 == 1) {
                A[i][n/2] = !A[i][n/2];
            }
        }
        return A;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> A = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    };
    for (const auto &vec : (new Solution())->flipAndInvertImage(A)) {
        for (const auto &val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
