// URL    : https://leetcode-cn.com/problems/reverse-string/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

/* ************************* */

// Time: 56ms  Memory: 15.2MB
class Solution {
public:
    void reverseString(std::vector<char> &s) {
        int len = s.size(), i = 0, j = len-1;
        for ( ; i < j; ++i, --j)
            if (s[i] != s[j])
                std::swap(s[i], s[j]);
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    (new Solution())->reverseString(s);
    for (auto c : s)
        std::cout << c << " ";
    // Ans: ["o","l","l","e","h"]
    std::cout << std::endl;
    s = {'H', 'a', 'n', 'n', 'a', 'h'};
    (new Solution())->reverseString(s);
    for (auto c : s)
        std::cout << c << " ";
    // Ans: ["h","a","n","n","a","H"]
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
