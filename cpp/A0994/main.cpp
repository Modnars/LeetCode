// URL    : https://leetcode-cn.com/problems/rotting-oranges/
// Author : Modnar
// Date   : 2020/03/04
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/rotting-oranges/solution/fu-lan-de-ju-zi-by-leetcode-solution/
// Time: 8ms(76.60%)  Memory: 15.4MB(5.40%)
class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>> &grid) {
        if (!grid.size()) return 0;
        // count记录当前剩余的好橘子的个数
        int ans = 0, m = grid.size(), n = grid[0].size(), count = 0;
        // dis记录位置(i, j)腐烂的时间
        std::vector<std::vector<int>> dis(m, std::vector<int>(n, -1)); // 初始化为-1
        std::queue<std::pair<int, int>> Q;
        for (int i = 0; i != m; ++i)
            for (int j = 0; j != n; ++j)
                if (grid[i][j] == 2) {
                    dis[i][j] = 0;
                    Q.push(std::make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    count += 1;
                }
        // BFS
        while (!Q.empty()) {
            auto pos = Q.front(); Q.pop();
            for (int i = 0; i != 4; ++i) {
                // (px, py)为当前结点周围的结点坐标
                int px = pos.first + x_dir[i], py = pos.second + y_dir[i];
                if (px == -1 || px == m || py == -1 || py == n || ~dis[px][py] ||
                        !grid[px][py])
                    continue;
                dis[px][py] = dis[pos.first][pos.second] + 1;
                Q.push(std::make_pair(px, py));
                if (grid[px][py] == 1) {
                    // 有新鲜橘子腐烂
                    count -= 1;
                    ans = dis[px][py];
                    if (!count)
                        break;
                }
            }
        }
        return count ? -1 : ans;
    }

private:
    static const std::vector<int> x_dir;
    static const std::vector<int> y_dir;
};

const std::vector<int> Solution::x_dir = {-1, 0, 1, 0};
const std::vector<int> Solution::y_dir = {0, 1, 0, -1};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> oranges = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    std::cout << (new Solution())->orangesRotting(oranges) << std::endl;
    // Ans: 4
    oranges = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    std::cout << (new Solution())->orangesRotting(oranges) << std::endl;
    // Ans: -1
    oranges = {{0, 2}};
    std::cout << (new Solution())->orangesRotting(oranges) << std::endl;
    // Ans: 0
    return EXIT_SUCCESS;
}
