// URL    : https://leetcode-cn.com/problems/string-to-integer-atoi/
// Author : Modnar
// Date   : 2020/02/21

#include <iostream>
#include <climits>
#include <string>

/* ************************* */

class Solution {
public:
    int myAtoi(std::string str) {
        int ans = 0, negative = 1, flag = 0;
        std::string::size_type i = 0;
        while (str[i] == ' ')
            ++i;
        for ( ; i < str.size(); ++i) {
            if (str[i] == '-') {
                if (flag)
                    return 0;
                flag = 1;
                negative = -1;
            } else if (str[i] == '+') {
                if (flag)
                    return 0;
                flag = 1;
            } else if (str[i] >= '0' && str[i] <= '9') {
                if (negative * ans > INT_MAX/10)
                    return INT_MAX;
                else if (negative * ans < INT_MIN/10)
                    return INT_MIN;
                else
                    ans = ans * 10 + (str[i] - '0');
            } else {
                return ans * negative;
            }
        }
        if (i == str.size())
            return ans * negative;
        return 0;
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
