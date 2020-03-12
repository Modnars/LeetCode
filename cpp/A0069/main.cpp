// URL    : https://leetcode-cn.com/problems/sqrtx/
// Author : Modnar
// Date   : 2020/03/12

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms(82.27%)  Memory: 7.4MB(100.00%)
class Solution {
public:
    int mySqrt(int x) {
        return static_cast<int>(std::sqrt(x));
    }
};

/* ************************* */

namespace AnsOne {
    class Solution {
    public:
        int mySqrt(int x) {
            long long int i = 0;
            while (i * i <= x)
                ++i;
            return i-1;
        }
    };
}

/**
 * 牛顿法求平方根
 */
namespace AnsTwo {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 8ms(45.76%)  Memory: 7.6MB(100.00%)
    class Solution {
    public:
        int mySqrt(int x) {
            if (x < 2)
                return x;
            double x0 = x, x1 = (x0 + x / x0) / 2.0;
            while (std::abs(x0 - x1) >= 1) {
                x0 = x1;
                x1 = (x0 + x / x0) / 2.0;
            }
            return static_cast<int>(x1);
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    for (int i = 0; i != 10; ++i)
        std::cout << solution->mySqrt(i) << std::endl;
    std::cout << solution->mySqrt(2147395600) << std::endl;
    return EXIT_SUCCESS;
}
