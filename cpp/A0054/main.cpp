// URL    : https://leetcode-cn.com/problems/spiral-matrix/
// Author : Modnar
// Date   : 2020/02/25

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms(68.36%)  Memory: 9.4MB(5.09%)
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        std::vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        int min_row = 0, max_row = matrix.size()-1, 
            min_col = 0, max_col = matrix[0].size()-1;
        while (min_row < max_row && min_col < max_col) {
            // std::cout << "1:";
            for (int j = min_col; j != max_col; ++j)
                ans.push_back(matrix[min_row][j]);
            // std::cout << "2:";
            for (int i = min_row; i != max_row; ++i)
                ans.push_back(matrix[i][max_col]);
            // std::cout << "3:";
            for (int j = max_col; j != min_col; --j)
                ans.push_back(matrix[max_row][j]);
            // std::cout << "4:";
            for (int i = max_row; i != min_row; --i)
                ans.push_back(matrix[i][min_col]);
            ++min_row; ++min_col;
            --max_row; --max_col;
        }
        if ((matrix.size() <= matrix[0].size()) && (matrix.size() & 1))
            for (int j = min_col; j <= max_col; ++j)
                ans.push_back(matrix[min_row][j]);
        if ((matrix.size() > matrix[0].size()) && (matrix[0].size() & 1))
            for (int i = min_row; i <= max_row; ++i)
                ans.push_back(matrix[i][min_col]);
        return ans;
    }
};

// 
//  1  2  3 | 1   2   3   4 |  1   2   3 |  1   2   3
//  4  5  6 | 5   6   7   8 |  4   5   6 |  4   5   6
//  7  8  9 | 9  10  11  12 |  7   8   9 |  7   8   9
//          |               | 10  11  12 | 10  11  12
//          |               |            | 13  14  15
//

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (const int &val : (new Solution())->spiralOrder(matrix))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3, 6, 9, 8, 7, 4, 5]
    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    for (const int &val : (new Solution())->spiralOrder(matrix))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    for (const int &val : (new Solution())->spiralOrder(matrix))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8]
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    for (const int &val : (new Solution())->spiralOrder(matrix))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3, 6, 9, 12, 15, 14, 13, 10, 7, 4, 5, 8, 11]
    return EXIT_SUCCESS;
}
