// URL    : https://leetcode-cn.com/contest/weekly-contest-181/problems/check-if-there-is-a-valid-path-in-a-grid/
// Author : Modnar
// Date   : 2020/03/22

#include <bits/stdc++.h>

/* ************************* */

// Time: 128ms(100.00%)  Memory: 22.8MB(100.00%)
class Solution {
public:
    bool hasValidPath(std::vector<std::vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int i, j, from;
        for (int x = 1; x != 5; ++x) {
            // 寻找可行的起始方向
            if (direction(grid[0][0], x) == -1) continue;
            i = 0, j = 0, from = x;
            for (int k = 0; k != m * n; ++k) {
                if (i == m-1 && j == n-1)
                    return true;
                int dir = direction(grid[i][j], from);
                if (dir < 0) break;
                // 获取下一个位置
                switch (dir) {
                    case 1: --i; from = 4; break;
                    case 2: --j; from = 3; break;
                    case 3: ++j; from = 2; break;
                    case 4: ++i; from = 1; break;
                }
                // 检查下一个位置是否可行
                if (i < 0 || j < 0 || i >= m || j >= n)
                    break;
                if (direction(grid[i][j], from) == -1)
                    break;
            }
        }
        return false;
    }

private:
    /**
     * 获取方向：
     *     通过传入当前位置的道路类型、起始方向来得到目标方向。
     *     当方向不合理时，返回-1。
     * 注意，此处不对type值进行检查，需要确保传入的type值是符合范围约束的。
     *
     * 方向定义：
     *        N:1
     *     W:2   E:3
     *        S:4
     */
    int direction(int type, int from) {
        const auto &curr = _DIR[type-1];
        if (from == curr[0])
            return curr[1];
        else if (from == curr[1])
            return curr[0];
        else
            return -1;
    }
    static const std::vector<std::vector<int>> _DIR;
};

const std::vector<std::vector<int>> Solution::_DIR = {{2, 3}, {1, 4}, {2, 4}, {3, 4}, {2, 1}, {1, 3}};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
    std::cout << (new Solution())->hasValidPath(grid) << std::endl;
    // Ans: 1 (true)
    grid = {{1, 2, 1}, {1, 2, 1}};
    std::cout << (new Solution())->hasValidPath(grid) << std::endl;
    // Ans: 0 (false)
    grid = {{1, 1, 2}};
    std::cout << (new Solution())->hasValidPath(grid) << std::endl;
    // Ans: 0 (false)
    grid = {{1, 1, 1, 1, 1, 1, 3}};
    std::cout << (new Solution())->hasValidPath(grid) << std::endl;
    // Ans: 1 (true)
    grid = {{2}, {2}, {2}, {2}, {2}, {2}, {6}};
    std::cout << (new Solution())->hasValidPath(grid) << std::endl;
    // Ans: 1 (true)
    grid = {{4, 1}, {6, 1}};
    std::cout << (new Solution())->hasValidPath(grid) << std::endl;
    // Ans: 1 (true)
    return EXIT_SUCCESS;
}
