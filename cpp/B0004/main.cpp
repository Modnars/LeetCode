// URL    : https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
// Author : Modnar
// Date   : 2020/03/10
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 对每行使用二分查找来搜索
 */
// Complexity: O(n*logm)
// Time: 36ms(54.10%)  Memory: 14.9MB(100.00%)
class Solution {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {
        for (const auto &row : matrix)
            if (binary_search(row, target))
                return true;
        return false;
    }

private:
    bool binary_search(const std::vector<int> &nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};

/* ************************* */

/**
 *     从矩阵右上角元素开始遍历，若matrix[i][j] < target，说明待搜索区域肯定在i+1行及
 * 以下；若matrix[i][j] > target，说明待搜索区域肯定在j-1行及以左。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: Time: O(m+n)  Space: O(1)
    // Time: 32ms(76.39%)  Memory: 14.8MB(100.00%)
    class Solution {
    public:
        bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {
            int m = matrix.size();
            if (!m) return false;
            int n = matrix[0].size();
            for (int i = 0, j = n-1; i != m && j != -1; )
                if (matrix[i][j] > target)
                    --j;
                else if (matrix[i][j] < target)
                    ++i;
                else
                    return true;
            return false;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    std::vector<std::vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    std::cout << solution->findNumberIn2DArray(matrix, 5) << std::endl;
    // Ans: 1 (true)
    std::cout << solution->findNumberIn2DArray(matrix, 20) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
