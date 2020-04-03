// URL    : https://leetcode-cn.com/problems/string-to-integer-atoi/
// Author : Modnar
// Date   : 2020/02/21

// ✅ : 2020/04/03

#include <bits/stdc++.h>

/* ************************* */

/**
 * 使用long long int
 *     使用一个long long来存储结果，当然这个数值的范围比INT的范围要大，因此直接拿这个
 * 值和INT_MAX及INT_MIN进行比较判断即可。
 */
// Time: 8ms(54.66%)  Memory: 8.5MB(25.88%)
// Time: 4ms(85.86%)  Memory: 6.2MB(100.00%) 2020.04.03
class Solution {
public:
    int myAtoi(std::string str) {
        long long int ans = 0;
        int i = 0, negative = 0, len = str.size();
        if (!len) return 0;   // 异常: 字符串为空
        while (str[i] == ' ') // 忽略起始的空格符
            ++i;
        if (str[i] == '-') {        // 如果是'-'，标记为负数
            ++i;
            negative = 1;
        } else if (str[i] == '+') { // 如果是'+'，忽略
            ++i;
        }
        for ( ; i != len; ++i) {
            if (isdigit(str[i])) {
                ans = 10 * ans + (str[i] - '0'); // 缓存结果，并用这个值进行溢出判断
                if (negative && -ans < INT_MIN) {        // 负数: 与INT_MIN比较
                    return INT_MIN;
                } else if (!negative && ans > INT_MAX) { // 正数: 与INT_MAX比较
                    return INT_MAX;
                }
            } else { // 针对"123OK"这一类，返回已确定的数值部分
                return negative ? -ans : ans;
            }
        }
        return negative ? -ans : ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->myAtoi("42") << std::endl;
    // Ans: 42
    std::cout << (new Solution())->myAtoi("   -42") << std::endl;
    // Ans: -42
    std::cout << (new Solution())->myAtoi("4193 with words") << std::endl;
    // Ans: 4193
    std::cout << (new Solution())->myAtoi("words and 987") << std::endl;
    // Ans: 0
    std::cout << (new Solution())->myAtoi("-91283472332") << std::endl;
    // Ans: -2147483648
    std::cout << (new Solution())->myAtoi("+2") << std::endl;
    // Ans: 2
    std::cout << (new Solution())->myAtoi("+-2") << std::endl;
    // Ans: 0
    std::cout << (new Solution())->myAtoi("-+1") << std::endl;
    // Ans: 0
    std::cout << (new Solution())->myAtoi("-2147483648") << std::endl;
    // Ans: -2147483648
    std::cout << (new Solution())->myAtoi("2147483648") << std::endl;
    // Ans: 2147483647
    std::cout << (new Solution())->myAtoi("-2147483649") << std::endl;
    // Ans: -2147483648
    return 0;
}
