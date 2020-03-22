// URL    : https://leetcode-cn.com/problems/longest-happy-prefix/
// Author : Modnar
// Date   : 2020/03/22
// Thanks : Zhiyong(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Failed: TIME_OUT
class Solution {
public:
    std::string longestPrefix(std::string s) {
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] != s[0]) continue;
            else if (check(s, i))
                return s.substr(i);
        }
        return "";
    }

private:
    bool check(const std::string &s, int p) {
        int i;
        for (i = 0; i != s.size()-p; ++i)
            if (s[i] != s[p+i])
                break;
        return p+i == s.size();
    }
};

/* ************************* */

/**
 * 直接对比子串来判断最长前缀，通过memcmp来避免内存拷贝问题。
 * 需要说明的是，直接使用substr进行比较会超出内存限制。
 */
namespace AnsOne {
    // Thanks: Zhiyong(@leetcode.cn)
    // Time: 660ms(100.00%)  Memory: 15.8MB(100.00%)
    class Solution {
    public:
        std::string longestPrefix(std::string s) {
            for (int i = 1; i != s.size(); ++i) {
                if (0 == memcmp(s.c_str(), s.c_str()+i, s.size()-i))
                    return s.substr(i);
            }
            return "";
        }
    };
}

/**
 * KMP算法
 */
namespace AnsTwo {
    // Thanks: 杨雁飞(@leetcode.cn)
    // Time: 52ms(100.00%)  Memory: 15.9MB(100.00%)
    class Solution {
    private:
        int next[int(1e5+50)];

    public:
        std::string longestPrefix(std::string s) {
            for (int i = 0, j = next[0] = -1; i < s.size(); next[++i] = ++j) {
                while (~j && s[j] != s[i]) j = next[j];
            }
            return s.substr(0, next[s.size()]);
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << (new Solution())->longestPrefix("ababab") << std::endl;
    // Ans: "abab"
    std::cout << (new Solution())->longestPrefix("leetcodeleet") << std::endl;
    // Ans: "leet"
    std::cout << (new Solution())->longestPrefix("a") << std::endl;
    // Ans: ""
    return EXIT_SUCCESS;
}
