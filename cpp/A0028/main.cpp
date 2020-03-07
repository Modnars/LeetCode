// URL    : https://leetcode-cn.com/problems/implement-strstr/
// Author : Modnar
// Date   : 2020/03/07

#include <bits/stdc++.h>

/* ************************* */

/**
 * 暴力枚举
 */
// Time: 8ms(57.74%)  Memory: 9.2MB(26.46%)
class Solution {
public:
    int strStr(const std::string &haystack, const std::string &needle) {
        if (!needle.size()) return 0;
        int slen = haystack.size(), plen = needle.size();
        for (int i = 0; i <= slen-plen; ++i) {
            int j;
            for (j = 0; j != needle.size(); ++j)
                if (needle[j] != haystack[i+j])
                    break;
            if (j == needle.size())
                return i;
        }
        return -1;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->strStr("hello", "ll") << std::endl;
    // Ans: 2
    std::cout << (new Solution())->strStr("aaaaa", "bba") << std::endl;
    // Ans: -1
    std::cout << (new Solution())->strStr("", "a") << std::endl;
    // Ans: -1
    return EXIT_SUCCESS;
}
