// URL    : https://leetcode-cn.com/problems/reverse-words-in-a-string/
// Author : Modnar
// Date   : 2020/04/10

#include <bits/stdc++.h>

/* ************************* */

// Time: 8ms(85.79%) Memory: 7.5MB(100.00%)
class Solution {
public:
    std::string reverseWords(std::string s) {
        int i = 0;
        bool needspace = false;
        for (int j = 0; j != s.size(); ++j) {
            if (s[j] != ' ') {
                s[i++] = s[j];
                needspace = true;
            } else if (s[j] == ' ' && needspace) {
                s[i++] = s[j];
                needspace = false;
            }
        }
        if (i == 0) return "";
        if (s[i-1] == ' ') --i;
        s = s.substr(0, i);
        reverse(s, 0, s.size()-1);
        int pos, beg = 0;
        while ((pos = s.find(' ', beg)) != std::string::npos) {
            reverse(s, beg, pos-1);
            beg = pos+1;
        }
        reverse(s, beg, s.size()-1);
        return s;
    }

private:
    void reverse(std::string &s, int l, int r) {
        for ( ; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                std::swap(s[l], s[r]);
            }
        }
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->reverseWords("the sky is blue") << "/" <<  std::endl;
    // Ans: "blue is sky the"
    std::cout << (new Solution())->reverseWords("  hello world!  ") <<  "/" << std::endl;
    // Ans: "world! hello"
    std::cout << (new Solution())->reverseWords("a good   example") <<  "/" << std::endl;
    // Ans: "example good a"
    std::cout << (new Solution())->reverseWords("") <<  "/" << std::endl;
    // Ans: ""
    std::cout << (new Solution())->reverseWords(" ") <<  "/" << std::endl;
    // Ans: ""
    return EXIT_SUCCESS;
}
