// URL    : https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
// Author : Modnar
// Date   : 2021/03/02

#include <bits/stdc++.h>

/* ************************* */

// Time: 160ms Memory: 15MB
class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>> &matrix) : matrix_(matrix) { }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; ++i) {
            ans += std::accumulate(matrix_[i].begin() + col1, matrix_[i].begin() + col2 + 1, 0);
        }
        return ans;
    }

private:
    std::vector<std::vector<int>> matrix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/* ************************* */

int main(int argc, char *const argv[]) {
    return EXIT_SUCCESS;
}

