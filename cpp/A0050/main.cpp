// URL    : https://leetcode-cn.com/problems/powx-n/
// Author : Modnar
// Date   : 2020/05/12
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms(54.31%)  Memory: 6.2MB(100.00%)
class Solution {
public:
    double myPow(double x, int n) {
        return std::pow(x, n);
    }
};

/* ************************* */

/**
 * 快速幂: 迭代算法
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/
    // Time: 0ms(100.00%)  Memory: 5.8MB(100.00%)
    class Solution {
    public:
        double quickMul(double x, long long N) {
            double ans = 1.0;
            // 贡献的初始值为 x
            double x_contribute = x;
            // 在对 N 进行二进制拆分的同时计算答案
            while (N > 0) {
                if (N % 2 == 1) {
                    // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                    ans *= x_contribute;
                }
                // 将贡献不断地平方
                x_contribute *= x_contribute;
                // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
                N /= 2;
            }
            return ans;
        }

        double myPow(double x, int n) {
            long long N = n;
            return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << (new Solution())->myPow(2.00000, 10) << std::endl;
    // Ans: 1024.0000
    std::cout << (new Solution())->myPow(2.10000, 3) << std::endl;
    // Ans: 9.26100
    std::cout << (new Solution())->myPow(2.00000, -2) << std::endl;
    // Ans: 0.25000
    return EXIT_SUCCESS;
}
