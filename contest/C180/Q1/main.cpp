// URL    : https://leetcode-cn.com/contest/weekly-contest-180/problems/lucky-numbers-in-a-matrix/
// Author : Modnar
// Date   : 2020/03/15

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> rows(m, 0), cols(n, 0), ans;
        for (int i = 0; i != m; ++i)
            for (int j = 0; j != n; ++j)
                if (matrix[i][j] < matrix[i][rows[i]])
                    rows[i] = j;
        for (int i = 0; i != m; ++i)
            for (int j = 0; j != n; ++j)
                if (matrix[i][j] > matrix[cols[j]][j])
                    cols[j] = i;
        for (int i = 0; i != m; ++i)
            for (int j = 0; j != n; ++j)
                if (matrix[i][rows[i]] == matrix[cols[j]][j])
                    ans.emplace_back(matrix[i][rows[i]]);
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    Solution *solution = new Solution();
    for (auto val : solution->luckyNumbers(matrix))
        std::cout << val << std::endl;
    return EXIT_SUCCESS;
}
