// URL    : https://leetcode-cn.com/problems/power-of-two/
// Author : Modnar
// Date   : 2020/02/23
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 位运算
 *     这种问题很容易想到用位运算解决，然而令我没有想到的是，LeetCode竟然不允许数据
 * 溢出？原代码中的检查标志是32，此时会发生溢出(怪我考虑欠妥，虽然我明知道会溢出)。
 * 改成31之后无影响。
 */
// Complexity: O(31)
// Time: 4ms  Memory: 8.2MB
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int check = 1;
        for (int i = 0; i != 31; ++i, check <<= 1)
            if (n == check)
                return true;
        return false;
    }
};

/* ************************* */

/**
 * 位运算(1)
 *     对于2的整数幂来说，其二进制数中仅有一个1。于是取数值的二进制表示的最右边的1，
 * 如果这个数和原数值相等，则可确定这个数中仅含一个1，那么这个数值就是2的幂。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: O(1)
    // Time: 8ms  Memory: 8MB
    class Solution {
    public:
        inline bool isPowerOfTwo(int n) {
            if (n == 0)
                return false;
            long x = n;
            return (x & (-x)) == x;
        }
    };
}

/**
 * 位运算(2)
 *     如果一个数为2的幂，那么其只包含一个1。以此为切入点，如果将数值的最右侧的1置为
 * 零，那么对于2的幂来说，操作后的结果为零；否则不为零。以此作为依据来进行判断。
 */
namespace AnsTwo {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: O(1)
    // Time: 4ms  Memory: 8MB
    class Solution {
    public:
        inline bool isPowerOfTwo(int n) {
            if (n == 0)
                return false;
            long x = n;
            return (x & (x - 1)) == 0;
        }
    };
}

/**
 * 关于位运算:
 *     获取二进制中最右边的1:
 *         x & (-x)
 *     将二进制最右边的1设置为0:
 *         x & (x - 1)
 */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->isPowerOfTwo(1) << std::endl;
    // Ans: 1 (true)
    std::cout << (new Solution())->isPowerOfTwo(3) << std::endl;
    // Ans: 0 (false)
    std::cout << (new Solution())->isPowerOfTwo(16) << std::endl;
    // Ans: 1 (true)
    std::cout << (new Solution())->isPowerOfTwo(218) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
