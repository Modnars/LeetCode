// URL    : https://leetcode-cn.com/problems/max-area-of-island/
// Author : Modnar
// Date   : 2020/03/15

#include <bits/stdc++.h>

/* ************************* */

/**
 * 深度优先搜索(DFS)
 *     遍历grid中的结点，若grid[i][j]为1，则对该点进行深度优先搜索，计算其所在“岛屿”
 * 的area，并更新ans。
 *     需要注意的是，每当添加一个点到area中时，应当更新该点状态为“已遍历”，这样操作可
 * 以通过修改grid中的值来实现。当然，如果要求不可修改grid内容，可将grid内容进行拷贝。
 *
 * 复杂度:
 *     由于每个顶点均只遍历一次，故算法复杂度为O(m*n)，其中尽管对一些顶点进行了DFS，但
 * 这些顶点后续不会被遍历，因而得到算法复杂度。
 *
 * 同理，使用广度优先搜索也可以实现解题。
 */
// Time: 8ms(99.40%)  Memory: 24.4MB(5.71%)
class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        int m = grid.size(), ans = 0;
        if (m == 0) return ans;
        int n = grid[0].size();
        std::stack<std::pair<int, int>> stk;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j]) {
                    // std::cout << "Here" << std::endl;
                    int area = 0;
                    stk.push(std::make_pair(i, j));
                    grid[i][j] = 0;
                    while (!stk.empty()) { // DFS
                        auto pos = stk.top();
                        stk.pop();
                        ++area;
                        ans = std::max(ans, area);
                        // std::cout << pos.first << " " << pos.second << std::endl;
                        for (int k = 0; k != 4; ++k) {
                            int tx = pos.first + dir_x[k], ty = pos.second + dir_y[k];
                            if (tx < 0 || tx == m || ty < 0 || ty == n || 
                                    !grid[tx][ty])
                                continue;
                            stk.push(std::make_pair(tx, ty));
                            grid[tx][ty] = 0;
                        }
                    }
                }
            }
        }
        return ans;
    }

private:
    const static std::vector<int> dir_x;
    const static std::vector<int> dir_y;
};

const std::vector<int> Solution::dir_x = {1, -1, 0, 0};
const std::vector<int> Solution::dir_y = {0, 0, -1, 1};

/* ************************* */

// 推荐阅读:
// Thanks: LeetCode(leetcode.cn)
// Solution: https://leetcode-cn.com/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-by-leetcode-solution/

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<std::vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    std::cout << solution->maxAreaOfIsland(grid) << std::endl;
    // Ans: 6
    grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
    std::cout << solution->maxAreaOfIsland(grid) << std::endl;
    // Ans: 0
    grid = {
        {1, 1, 0, 0, 0}, 
        {1, 1, 0, 0, 0}, 
        {0, 0, 0, 1, 1}, 
        {0, 0, 0, 1, 1}
    };
    std::cout << solution->maxAreaOfIsland(grid) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
