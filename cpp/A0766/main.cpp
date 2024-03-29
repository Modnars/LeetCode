// URL    : https://leetcode-cn.com/problems/toeplitz-matrix/
// Author : Modnar
// Date   : 2021/02/22

#include <bits/stdc++.h>

/* ************************* */

// Time: 16ms Memory: 17MB
class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (!judgeSingleLine(i, 0, matrix)) {
                return false;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (!judgeSingleLine(0, j, matrix)) {
                return false;
            }
        }
        return true;
    }

private:
    bool judgeSingleLine(int i, int j, const std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int k = std::min(m-i, n-j);
        int val = matrix[i][j];
        for (int offset = 1; offset < k; ++offset) {
            if (matrix[i+offset][j+offset] != val) {
                return false;
            }
        }
        return true;
    }
};

/* ************************* */

namespace AnsOne {

// Time: 24ms Memory: 17.1MB
class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
    
} // namespace AnsOne


int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };
    std::cout << (new AnsOne::Solution())->isToeplitzMatrix(matrix) << std::endl;
    matrix = {
        {1, 2},
        {2, 2}
    };
    std::cout << (new AnsOne::Solution())->isToeplitzMatrix(matrix) << std::endl;
    return EXIT_SUCCESS;
}
