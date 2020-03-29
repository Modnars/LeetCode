// URL    : https://leetcode-cn.com/problems/as-far-from-land-as-possible/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    int maxDistance(std::vector<std::vector<int>> &grid) {
        std::queue<std::pair<int, int>> Q;
        int N = grid.size(), ans = -1;
        for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j)
                if (grid[i][j])
                    Q.push(std::make_pair(i, j));
        if (Q.size() == N*N) return ans;
        int count = N * N - Q.size();
        while (!Q.empty()) {
            int sz = Q.size();
            if (count) ++ans;
            for (int i = 0; i != sz; ++i) {
                int px = Q.front().first, py = Q.front().second;
                Q.pop();
                if (!grid[px][py]) --count;
                grid[px][py] = 1;
                for (int k = 0; k != 4; ++k) {
                    int tx = px + dx[k], ty = py + dy[k];
                    if (tx < 0 || tx >= N || ty < 0 || ty >= N || grid[tx][ty]) 
                        continue;
                    Q.push(std::make_pair(tx, ty));
                }
            }
        }
        return ans;
    }

private:
    static const std::vector<int> dx;
    static const std::vector<int> dy;
};

const std::vector<int> Solution::dx = {0, 1, 0, -1};
const std::vector<int> Solution::dy = {1, 0, -1, 0};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    std::cout << (new Solution())->maxDistance(grid) << std::endl;
    // Ans: 2
    grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    std::cout << (new Solution())->maxDistance(grid) << std::endl;
    // Ans: 4
    grid = {
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
        {1, 1, 0, 1, 1, 1, 0, 1, 1, 0}, 
        {0, 1, 1, 0, 1, 0, 0, 1, 0, 0}, 
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 
        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1}, 
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 1}, 
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, 
        {1, 1, 0, 1, 1, 1, 1, 1, 0, 0}};
    std::cout << (new Solution())->maxDistance(grid) << std::endl;
    // Ans: 2
    return EXIT_SUCCESS;
}
