// URL    : https://leetcode-cn.com/problems/reverse-integer/
// Author : Modnar
// Date   : 2020/02/20

#include <iostream>
#include <climits>
#include <string>

/* ************************* */

/**
 * 正常计算即可，针对溢出情况进行判断。当程序不能引入<climits>时，可以用:
 * max_value = 0x7FFFFFFF, min_value = 0x80000000来替换INT_MAX, INT_MIN。
 */
// Time: 4ms  Memory: 8.1MB
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            // 首先判断运算结果是否可能溢出
            // if (ans > 0 && ans > INT_MAX/10)
            //     return 0;
            // else if (ans < 0 && ans < INT_MIN/10)
            //     return 0; 
            if (ans > INT_MAX/10 || ans < INT_MIN/10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

/* ************************* */

// Time: 4ms  Memory: 8.1MB
namespace AnsOne {
    /**
     * 来自LeetCode评论区的算法，通过令结果为long类型，进行正常运算，得到结果再与
     * int类型的最大值最小值比较判断是否溢出即可。
     *
     * 这种做法可以避免过多的判断流程，从而提高程序时间性能。
     */
    class Solution {
    public:
        int reverse(int x) {
            int max_value = 0x7FFFFFFF, min_value = 0x80000000;
            long ans = 0;
            for ( ; x; ans=ans*10+x%10, x/=10)
                ;
            return (ans > max_value || ans < min_value) ? 0 : ans;
        }
    };
}

int main(int argc, char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << (new Solution())->reverse(123) << std::endl;
    // Ans: 321
    std::cout << (new Solution())->reverse(-123) << std::endl;
    // Ans: -321
    std::cout << (new Solution())->reverse(120) << std::endl;
    // Ans: 21
    return 0;
}
