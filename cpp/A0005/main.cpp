// URL    : https://leetcode-cn.com/problems/longest-palindromic-substring/
// Author : Modnar
// Date   : 2020/02/21

#include <string>
#include <vector>
#include <iostream>

/* ************************* */

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s == "")
            return "";
        int maxLen = 0, maxIndex = 0;
        std::vector<std::vector<int>> matrix(s.size(), std::vector<int>(s.size(), 0));
        for (int i = 0; i != s.size(); ++i)
            matrix[i][i] = 1;
        for (int i = 0; i != s.size(); ++i) {
            for (int j = s.size(); j != -1; --j) {
                if (s[i] == s[j]) {
                    if (i == s.size()-1 || j == 0)
                        matrix[i][j] = 0;
                    else {
                        matrix[i][j] = matrix[i+1][j-1] + 1;
                        if (matrix[i][j] > maxLen) {
                            maxLen = matrix[i][j];
                            maxIndex = i;
                        }
                    }
                }
            }
        }
        return s.substr(maxIndex, maxLen+1);
    }
};

/* ************************* */

namespace AnsOne {
    class Solution {
    public:
        std::string longestPalindrome(const std::string &s) {
            return "";
        }
    };
}

int main(int argc, const char *argv[]) {
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
