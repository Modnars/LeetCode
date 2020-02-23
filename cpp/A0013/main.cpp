// URL    : https://leetcode-cn.com/problems/roman-to-integer/
// Author : Modnar
// Date   : 2020/02/23
// Thanks : ⚗ Knife丶👆👆👆(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 使用一个pre来记录前一位数值
 *     由于针对pre<val的情况，只需要记录一位pre即可(即一次判断即可确定具体计算值)，
 * 因而较为简单。
 *     如果不是如此，比如如果8表示为IIX的话，则需要进一步判断。
 */
class Solution {
public:
    int romanToInt(std::string s) {
        if (s == "") return 0;
        int len = s.size(), pre = Int(s[0]), ans = pre;
        for (int i = 1; i != len; ++i) {
            int val = Int(s[i]);
            if (pre < val)
                ans += val - pre - pre; // 将已经被加过的pre减去
            else
                ans += val;
            pre = val;
        }
        return ans;
    }

private:
    int Int(char ch) {
        int val = 0;
        switch (ch) {
            case 'I':
                val = 1;    break;
            case 'V':
                val = 5;    break;
            case 'X':
                val = 10;   break;
            case 'L':
                val = 50;   break;
            case 'C':
                val = 100;  break;
            case 'D':
                val = 500;  break;
            case 'M':
                val = 1000; break;
            default:
                val = 0;    break;
        }
        return val;
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks: ⚗ Knife丶👆👆👆(@leetcode.cn)
    // Time: 56ms  Memory: 19.4MB
    class Solution {
    public:
        int romanToInt(std::string s) {
            std::unordered_map<std::string, int> m = {
                {"I", 1},    {"IV", 3},  {"IX", 8}, {"V", 5},   {"X", 10}, 
                {"XL", 30},  {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, 
                {"CM", 800}, {"D", 500}, {"M", 1000}};
            int r = m[s.substr(0, 1)];
            for(int i=1; i<s.size(); ++i){
                std::string two = s.substr(i-1, 2);
                std::string one = s.substr(i, 1);
                r += m[two] ? m[two] : m[one];
            }
            return r;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->romanToInt("III") << std::endl;
    // Ans: 3
    std::cout << (new Solution())->romanToInt("IV") << std::endl;
    // Ans: 4
    std::cout << (new Solution())->romanToInt("IX") << std::endl;
    // Ans: 9
    std::cout << (new Solution())->romanToInt("LVIII") << std::endl;
    // Ans: 58
    std::cout << (new Solution())->romanToInt("MCMXCIV") << std::endl;
    // Ans: 1994
    return EXIT_SUCCESS;
}
