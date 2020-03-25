// URL    : https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
// Author : Modnar
// Date   : 2020/03/25
// Thanks : samperson1997(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 *     计算所有“相差”面积。计算两个相邻柱体之间相差的部分，就是需要统计的面积值。
 * 此外，若该位置有方块堆叠，则加上上下两个面的面积。
 *     计算“相差”面积，可以避免“坑”带来的困扰。
 */
// Time: 28ms(5.83%)  Memory: 8.7MB(100.00%)
class Solution {
public:
    int surfaceArea(std::vector<std::vector<int>> &grid) {
        int ans = 0, N = grid.size();
        std::vector<int> pre_col_heights(N, 0);
        for (int i = 0; i != N; ++i) {
            int pre_row_height = 0;
            for (int j = 0; j != N; ++j) {
                int height = grid[i][j];
                if (height) 
                    ans += 2; // 上下面的面积
                ans += std::abs(height - pre_row_height);     // 统计当前行面积
                ans += std::abs(height - pre_col_heights[j]); // 统计当前列面积
                pre_row_height = height;     // 为后续计算“相差”高度保留
                pre_col_heights[j] = height; // 为后续计算“相差”高度保留
            }
            ans += pre_row_height;
        }
        // 对于最后一行的每列高度，记得添加上
        for (int i = 0; i != N; ++i)
            ans += pre_col_heights[i];
        return ans;
    }
};

/* ************************* */

/**
 * 计算全部柱体面积再减去相邻重叠面积
 *     计算每个柱体的面积，并减去相邻柱体之间重叠的面积(注意乘以2)。两柱体重叠的面积
 * 就是相邻柱体高度较低的一个柱体的高度乘以2。这样可以很好地处理“坑”的特殊情况。
 */
namespace AnsOne {
    // Thanks: samperson1997(@leetcode.cn)
    // Time: 28ms(5.83%)  Memory: 9MB(100.00%)
    class Solution {
    public:
        int surfaceArea(std::vector<std::vector<int>> &grid) {
            int N = grid.size(), ans = 0;
            for (int i = 0; i != N; ++i)
                for (int j = 0; j != N; ++j) {
                    int height = grid[i][j];
                    if (height) // 如果有方块堆叠，计算该“柱体”的表面积
                        ans += (height << 2) + 2;
                    if (i) // 减去当前柱体和上一行相邻柱体的重叠面积
                        ans -= (std::min(grid[i-1][j], height) << 1);
                    if (j) // 减去当前柱体和前一列相邻柱体的重叠面积
                        ans -= (std::min(grid[i][j-1], height) << 1);
                }
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<std::vector<int>> grid = {{2}};
    std::cout << (new Solution())->surfaceArea(grid) << std::endl;
    // Ans: 10
    grid = {{1, 2}, {3, 4}};
    std::cout << (new Solution())->surfaceArea(grid) << std::endl;
    // Ans: 34
    grid = {{1, 0}, {0, 2}};
    std::cout << (new Solution())->surfaceArea(grid) << std::endl;
    // Ans: 16
    grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::cout << (new Solution())->surfaceArea(grid) << std::endl;
    // Ans: 32
    grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    std::cout << (new Solution())->surfaceArea(grid) << std::endl;
    // Ans: 46
    return EXIT_SUCCESS;
}
