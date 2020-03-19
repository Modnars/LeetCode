// URL    : https://leetcode-cn.com/problems/longest-palindromic-substring/
// Author : Modnar
// Date   : 2020/02/21
// Thanks : Official(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 中心拓展算法
 *     详情请参阅:https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode/
 */
// Thanks: Official(@leetcode.cn)
// Time: 60ms  Memory: 15.9MB
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int maxLen = 0, len = s.size(), val;
        std::string ans = "";
        for (int i = 0; i != len; ++i) {
            val = palindromeLength(s, i, i);
            if (maxLen < val ) {
                maxLen = val;
                ans = s.substr(i-(maxLen/2), maxLen);
            }
            val = palindromeLength(s, i, i+1);
            if (maxLen < val) {
                maxLen = val;
                ans = s.substr(i+1-(maxLen/2), maxLen);
            }
        }
        return ans;
    }

private:
    /* 计算在s的某个位置处的最长回文子串长 */
    int palindromeLength(const std::string &s, int l, int r) {
        int retVal = 0, len = s.size();
        if (l == r) {
            retVal += 1;
            --l;
            ++r;
        }
        for ( ; l != -1 && r != len; --l, ++r) {
            if (s[l] != s[r])
                return retVal;
            retVal += 2;
        }
        return retVal;
    }
};

/* ************************* */

/**
 * 修改自官方写法
 */
namespace AnsOne {
    // Thanks: Official(@leetcode.cn)
    // Time: 20ms  Memory: 9.1MB
    class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            int beg = 0, len = s.size(), maxLen = 0;
            for (int i = 0; i != len; ++i) {
                int len1 = expendAroundCenter(s, i, i), 
                    len2 = expendAroundCenter(s, i, i+1);
                if (maxLen < std::max(len1, len2)) {
                    maxLen = std::max(len1, len2);
                    beg = i - (maxLen-1) / 2;
                }
            }
            return s.substr(beg, maxLen);
        }

    private:
        /* 计算在s的某个位置处的最长回文子串长 */
        int expendAroundCenter(const std::string &s, int l, int r) {
            int len = s.size();
            while (l != -1 && r != len && s[l] == s[r]) {
                --l; ++r;
            }
            return r - l - 1;
        }
    };
}

/**
 * 补充: 关于整数取整
 *     “/”在C/C++中对整数来说总是表示“向下取整”。
 *     比如: 3/2 = [1.5] = 1; 4/2 = [2.0] = 2。
 *
 *     为了对val/2.0实现“向上取整”，只需使用(val+1)/2即可。
 *     比如: (3+1)/2 = [2.0] = 2; (4+1)/2 = [2.5] = 2。
 *
 *          c  d  a  b  a  c  d         maxLen = 3
 *          0  1  2  3  4  5  6
 *                p  i                  p = i - (maxLen-1)/2;
 *
 *          c  d  a  b  b  a  c  d      maxLen = 4
 *          0  1  2  3  4  5  6  7
 *                p  i                  p = i - (maxLen-1)/2;
 */

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << (new Solution())->longestPalindrome("babad") << std::endl;
    // Ans: "bab"
    std::cout << (new Solution())->longestPalindrome("") << std::endl;
    // Ans: ""
    std::cout << (new Solution())->longestPalindrome("aacdefcaa") << std::endl;
    // Ans: "aa"
    std::cout << (new Solution())->longestPalindrome("aaaa") << std::endl;
    // Ans: "aaaa"
    return 0;
}
