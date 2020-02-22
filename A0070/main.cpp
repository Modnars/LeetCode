// URL    : https://leetcode-cn.com/problems/climbing-stairs/
// Author : Modnar
// Date   : 2020/02/22

#include <vector>
#include <cstdlib>
#include <iostream>

/* ************************* */

/**
 * 动态规划
 *     只需要关注最后一步是选择走一步还是两步。如果选择一步，那么走法就是ans[n-1]种；
 * 如果选择两步，那么走法就是ans[n-2]种。故所有可能的走法就是ans[n-1]+ans[n-2]种。
 */
// Time: 4ms  Memory: 8.5MB
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        std::vector<int> ans(n);
        ans[0] = 1;
        ans[1] = 2;
        for (int i = 2; i != n; ++i)
            ans[i] = ans[i-1] + ans[i-2];
        return ans[n-1];
    }
};

/* ************************* */

// Thanks: Official(@leetcode.cn)
// Time: 0ms  Memory: 8.2MB
namespace AnsOne {
    /**
     * 可以确定，题解就是求解斐波那契数列
     *     因此，可以利用斐波那契数列求法解题。
     */
    class Solution {
    public:
        int climbStairs(int n) {
            if (n == 1) return 1;
            int first = 1, second = 2, third;
            for (int i = 3; i <= n; ++i) {
                third = first + second;
                first = second;
                second = third;
            }
            return second;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->climbStairs(1) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->climbStairs(2) << std::endl;
    // Ans: 2
    std::cout << (new Solution())->climbStairs(3) << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
