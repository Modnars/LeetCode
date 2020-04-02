// URL    : https://leetcode-cn.com/problems/game-of-life/
// Author : Modnar
// Date   : 2020/04/02

#include <bits/stdc++.h>

/**
 * 拷贝一个board，并使用其作为参考，在原board上进行修改
 */
/* ************************* */

// Complexity: Time: O(m*n)  Space: O(m*n)
// Time: 0ms(100.00%)  Memory: 7MB(100.00%)
class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>> &board) {
        auto copy = board;
        for (int i = 0; i != board.size(); ++i)
            for (int j = 0; j != board[0].size(); ++j) {
                board[i][j] = 0;
                process(copy, i, j, board);
            }
    }

private:
    void process(std::vector<std::vector<int>> &board, int m, int n, 
            std::vector<std::vector<int>> &ans) {
        int alive = 0;
        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int tx = m + i, ty = n + j;
                if (tx < 0 || ty < 0 || tx >= board.size() || ty >= board[0].size())
                    continue;
                alive += board[tx][ty];
            }
        if (board[m][n]) {
            if (alive == 2 || alive ==3)
                ans[m][n] = 1;
        } else if (alive == 3) {
            ans[m][n] = 1;
        }
    }
};

/* ************************* */

/**
 * 直接在原board上进行修改，增加复合状态2(从0到1)和状态-1(从1到0)
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: Time: O(m*n)  Space: O(1)
    // Time: 0ms(100.00%)  Memory: 6.8MB(100.00%)
    class Solution {
    public:
        void gameOfLife(std::vector<std::vector<int>> &board) {
            for (int i = 0; i != board.size(); ++i)
                for (int j = 0; j != board[0].size(); ++j)
                    process(board, i, j);
            for (int i = 0; i != board.size(); ++i)
                for (int j = 0; j != board[0].size(); ++j)
                    if (board[i][j] == -1)
                        board[i][j] = 0;
                    else if (board[i][j] == 2)
                        board[i][j] = 1;
        }

    private:
        void process(std::vector<std::vector<int>> &board, int x, int y) {
            int alive = 0;
            for (int i = -1; i <= 1; ++i)
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) continue;
                    int tx = x + i, ty = y + j;
                    if (tx < 0 || ty < 0 || tx >= board.size() || ty >= board[0].size())
                        continue;
                    alive += (board[tx][ty] == 1 || board[tx][ty] == -1);
                }
            if (board[x][y]) {
                if (alive < 2 || alive > 3)
                    board[x][y] = -1;
            } else {
                if (alive == 3)
                    board[x][y] = 2;
            }
        }
    };
}

int main(int argc, const char *argv[]) {
    // using Solution = AnsOne::Solution;
    std::vector<std::vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    (new Solution())->gameOfLife(board);
    for (const auto &row : board) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
