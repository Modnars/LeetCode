// URL    : https://leetcode-cn.com/problems/number-of-islands/
// Author : Modnar
// Date   : 2020/04/20
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Failed: TIME_OUT
class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i)
            for (int j = 0; j != grid[0].size(); ++j)
                if (grid[i][j] == '1') {
                    ++ans;
                    bfs(grid, i, j);
                }
        return ans;
    }

private:
    void bfs(std::vector<std::vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        std::queue<std::pair<int, int>> Q;
        if (grid[i][j] == '1')
            Q.push(std::make_pair(i, j));
        while (!Q.empty()) {
            int px = Q.front().first, py = Q.front().second;
            Q.pop();
            grid[px][py] = '0';
            for (int k = 0; k != 4; ++k) {
                int tx = px + dir_x[k], ty = py + dir_y[k];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[tx][ty] == '0')
                    continue;
                Q.push(std::make_pair(tx, ty));
            }
        }
    }
    static const std::vector<int> dir_x;
    static const std::vector<int> dir_y;
};

const std::vector<int> Solution::dir_x = {0, 1, 0, -1};
const std::vector<int> Solution::dir_y = {1, 0, -1, 0};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 12ms(86.76%)  Memory: 8.4MB(100.00%)
    // Complexity: Time: O(M*N)  Space: O(M*N)
    class Solution {
    private:
        void dfs(std::vector<std::vector<char>> &grid, int r, int c) {
            int nr = grid.size();
            int nc = grid[0].size();

            grid[r][c] = '0';
            if (r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
            if (r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
            if (c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
            if (c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
        }

    public:
        int numIslands(std::vector<std::vector<char>> &grid) {
            int nr = grid.size();
            if (!nr) return 0;
            int nc = grid[0].size();

            int num_islands = 0;
            for (int r = 0; r < nr; ++r) {
                for (int c = 0; c < nc; ++c) {
                    if (grid[r][c] == '1') {
                        ++num_islands;
                        dfs(grid, r, c);
                    }
                }
            }

            return num_islands;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    std::cout << (new Solution())->numIslands(grid) << std::endl;
    // Ans: 1
    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout << (new Solution())->numIslands(grid) << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
