// URL    : https://leetcode-cn.com/problems/valid-sudoku/
// Author : Modnar
// Date   : 2020/03/09
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Time: 16ms(71.02%)  Memory: 9.5MB(60.83%)
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        return (checkRow(board) && checkCol(board) && checkPalace(board));
    }

private:
    // 为了节省空间，设定为int型
    static std::vector<int> check;

    bool checkRow(const std::vector<std::vector<char>> &board) {
        for (const auto &row : board) {
            check.clear(); check.resize(10);
            for (const auto &val : row) {
                if (val == '.')
                    continue;
                else if (!check[val-'0'])
                    check[val-'0'] = 1;
                else
                    return false;
            }
        }
        return true;
    }

    bool checkCol(const std::vector<std::vector<char>> &board) {
        for (int j = 0; j != 9; ++j) {
            check.clear(); check.resize(10);
            for (int i = 0; i != 9; ++i) {
                if (board[i][j] == '.')
                    continue;
                else if (!check[board[i][j]-'0'])
                    check[board[i][j]-'0'] = 1;
                else
                    return false;
            }
        }
        return true;
    }

    bool checkPalace(const std::vector<std::vector<char>> &board) {
        for (int k = 0; k != 9; ++k) {
            int px = (k * 3) / 9, py = (k * 3) % 9;
            check.clear(); check.resize(10);
            for (int i = px*3; i < px*3+3; ++i) {
                for (int j = py; j < py+3; ++j) {
                    if (board[i][j] == '.')
                        continue;
                    else if (!check[board[i][j]-'0'])
                        check[board[i][j]-'0'] = 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};

std::vector<int> Solution::check;

/* ************************* */

/**
 * 一次迭代
 *     可以通过i,j获取属于第x个宫，x = (i / 3) * 3 + j / 3。
 *     因而可以通过这样的方法一次迭代求解。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 16ms(71.02%)  Memory: 11.1MB(27.88%)
    class Solution {
    public:
        bool isValidSudoku(std::vector<std::vector<char>> &board) {
            // 注意空间初始化为10，以便于直接使用board[i][j]-'0'作为下标
            std::vector<std::vector<bool>> rows(9, std::vector<bool>(9, false));
            std::vector<std::vector<bool>> cols(9, std::vector<bool>(9, false));
            std::vector<std::vector<bool>> palaces(9, std::vector<bool>(9, false));
            for (int i = 0; i != 9; ++i)
                for (int j = 0; j != 9; ++j)
                    if (board[i][j] == '.')
                        continue;
                    else if (rows[i][board[i][j]-'1'] || cols[j][board[i][j]-'1'] ||
                            palaces[(i/3)*3+j/3][board[i][j]-'1'])
                        return false;
                    else {
                        rows[i][board[i][j]-'1'] = true;
                        cols[j][board[i][j]-'1'] = true;
                        palaces[(i/3)*3+j/3][board[i][j]-'1'] = true;
                    }
            return true;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::cout << (new Solution())->isValidSudoku(board) << std::endl;
    // Ans: 1 (true)
    board = {
        {'.', '.', '.', '.', '5', '.', '.', '1', '.'}, 
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'}, 
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'}, 
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'}, 
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'}, 
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'}, 
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
    };
    std::cout << (new Solution())->isValidSudoku(board) << std::endl;
    // Ans: 0 (false)
    board = {
        {'.', '.', '.', '.', '.', '.', '5', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'9', '3', '.', '.', '2', '.', '4', '.', '.'}, 
        {'.', '.', '7', '.', '.', '.', '3', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '3', '4', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '3', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '5', '2', '.', '.'}
    };
    std::cout << (new Solution())->isValidSudoku(board) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
