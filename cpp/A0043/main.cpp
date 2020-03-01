// URL    : https://leetcode-cn.com/problems/multiply-strings/
// Author : Modnar
// Date   : 2020/03/01
// Thanks : 无聊刷刷(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: 无聊刷刷(@leetcode.cn)
// Complexity: Time: O(m*n)  Space: O(m+n)
// Time: 4ms(97.29%)  Memory: 8.8MB(55.82%)
class Solution {
public:
    static std::string multiply(const std::string &num1, const std::string &num2) {
        int len1 = num1.size(), len2 = num2.size();
        std::string res(len1+len2, '0');
        for (int i = len2-1; i != -1; --i)
            for (int j = len1-1; j != -1; --j) {
                int temp = (res[i+j+1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                res[i+j+1] = temp % 10 + '0'; // 当前位
                // 前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转换为char
                // 类型，所以此处无需加'0'。
                res[i+j] += temp / 10;
            }
        for (int i = 0; i != len1+len2; ++i)
            if (res[i] != '0')
                return res.substr(i);
        return "0";
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    using std::atoi;
    using std::to_string;
    std::cout << (new Solution())->multiply("2", "3") << std::endl;
    // Ans: "6"
    std::cout << (new Solution())->multiply("123", "456") << std::endl;
    // Ans: "56088"
    for (int i = 0; i != 101; ++i)
        for (int j = 0; j != 101; ++j)
            if (i * j != atoi(Solution::multiply(to_string(i), to_string(j)).c_str()))
                std::cout << i << " * " << j << std::endl;
    return EXIT_SUCCESS;
}
