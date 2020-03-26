// URL    : https://leetcode-cn.com/problems/available-captures-for-rook/submissions/
// Author : Modnar
// Date   : 2020/03/26

#include <bits/stdc++.h>

/* ************************* */

// Time: 0ms(100.00%)  Memory: 6.5MB(100.00%)
class Solution {
public:
    int numRookCaptures(std::vector<std::vector<char>> &board) {
        int px = 0, py = 0, ans = 0;
        // 首先，找到“车”的位置
        for (int i = 0; i != 8; ++i)
            for (int j = 0; j != 8; ++j)
                if (board[i][j] == 'R')
                    px = i, py = j;
        for (int i = 0; i != 4; ++i) {
            int nx = px, ny = py;
            while (true) {
                nx = nx + dir_x[i], ny = ny + dir_y[i];
                // 如果位置不在棋盘上，或位置上存在本方的“象”，退出该方向的查找
                if (nx < 0 || ny < 0 || nx == 8 || ny == 8 || board[nx][ny] == 'B')
                    break;
                // 若当前查找方向上存在对方的“卒”，则更新答案
                if (board[nx][ny] == 'p') {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }

private:
    static const std::vector<int> dir_x;
    static const std::vector<int> dir_y;
};

const std::vector<int> Solution::dir_x = {0, 1, 0, -1};
const std::vector<int> Solution::dir_y = {1, 0, -1, 0};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<std::vector<char>> board ={
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'p', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'R', '.', '.', '.', 'p'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'p', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    std::cout << (new Solution())->numRookCaptures(board) << std::endl;
    // Ans: 3
    board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'}, 
        {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'}, 
        {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'}, 
        {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'}, 
        {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    std::cout << (new Solution())->numRookCaptures(board) << std::endl;
    // Ans: 0
    board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'p', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'p', '.', '.', '.', '.'}, 
        {'p', 'p', '.', 'R', '.', 'p', 'B', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'B', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'p', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    std::cout << (new Solution())->numRookCaptures(board) << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
