// URL    : https://leetcode-cn.com/problems/nim-game/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

/* ************************* */

/**
 * 直接分析
 *     显然，这是一个先手有利游戏。由于玩家回合时必须要指定数字，且数字范围为1~3，
 * 因此可知，对于先手玩家来说，只要n不是4的倍数，必定获胜。
 */
// Time: 4ms  Memory: 8.1MB
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4) != 0;
    }
};

/**
 * 利用位运算进行性能优化
 */
namespace AnsOne {
    // Time: 4ms  Memory: 8MB
    class Solution {
    public:
        inline bool canWinNim(int n) {
            return (n & 0x3) != 0;
        }
    };
}

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->canWinNim(4) << std::endl;
    return EXIT_SUCCESS;
}
