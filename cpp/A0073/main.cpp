// URL    : https://leetcode-cn.com/problems/set-matrix-zeroes/
// Author : Modnar
// Date   : 2020/03/06
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

void print(const std::vector<std::vector<int>> &);

/* ************************* */

// Complexity: Time: O(n^2)  Space: O(m+n)
// Time: 12ms(92.62%)  Memory: 14.7MB(5.04%)
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        if (matrix.size() == 0) return;
        std::set<int> rows, cols;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i != m; ++i)
            for (int j = 0; j != n; ++j)
                if (!matrix[i][j]) {
                    rows.insert(i);
                    cols.insert(j);
                }
        for (const int &row : rows)
            for (int j = 0; j != n; ++j)
                matrix[row][j] = 0;
        for (const int &col : cols)
            for (int i = 0; i != m; ++i)
                matrix[i][col] = 0;
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/set-matrix-zeroes/solution/ju-zhen-zhi-ling-by-leetcode/
    // Complexity: Time: O(MxN)  Space: O(1)
    // Time: 16ms(73.52%)  Memory: 14.4MB(5.04%)
    class Solution {
    public:
        void setZeroes(std::vector<std::vector<int>> &matrix) {
            if (matrix.size() == 0) return;
            int m = matrix.size(), n = matrix[0].size();
            bool isCol = false;
            for (int i = 0; i != m; ++i) {
                if (matrix[i][0] == 0)
                    isCol = true;
                for (int j = 1; j != n; ++j)
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
            }
            for (int i = 1; i != m; ++i)
                for (int j = 1; j != n; ++j)
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
            if (matrix[0][0] == 0)
                for (int j = 0; j != n; ++j)
                    matrix[0][j] = 0;
            if (isCol)
                for (int i = 0; i != m; ++i)
                    matrix[i][0] = 0;
        }
    };
}

void print(const std::vector<std::vector<int>> &nums) {
    for (const auto &row : nums) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<std::vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    (new Solution())->setZeroes(nums);
    print(nums);
    // Ans:
    // 1 0 1
    // 0 0 0
    // 1 0 1
    nums = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    (new Solution())->setZeroes(nums);
    print(nums);
    // Ans:
    // 0 0 0 0
    // 0 4 5 0
    // 0 3 1 0
    nums = {{1, 1, 1}, {0, 1, 2}};
    (new Solution())->setZeroes(nums);
    print(nums);
    return EXIT_SUCCESS;
}
