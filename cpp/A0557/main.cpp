// URL    : https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

/* ************************* */

// Time: 28ms  Memory: 11.9MB
class Solution {
public:
    std::string reverseWords(std::string s) {
        if (s == "") return "";
        int spacePos = 0, l = 0, r = 0;
        for (spacePos = s.find(' '); spacePos != std::string::npos; 
                spacePos = s.find(' ', spacePos+1)) {
            r = spacePos - 1;
            for ( ; l < r; ++l, --r)
                if (s[l] != s[r])
                    std::swap(s[l], s[r]);
            l = spacePos + 1;
        }
        // 由于spacePos为npos时，还有最后一段未逆序，因而此处需要单独处理这一段
        for (r = s.size()-1; l < r; ++l, --r)
            if (s[l] != s[r])
                std::swap(s[l], s[r]);
        return s;
    }
};

/* ************************* */

/**
 * 针对默认题解的简易优化
 *     由于默认题解需要单独处理最后一段，其原因在于s.find(' ', pos)的最后返回值为
 * npos，如果这个返回值为s.size()，那么就可以使其按照循环内流程正确处理最后一段，
 * 因此，可以自己写一个函数来针对返回值进行修改。考虑到执行效率，可以将这个函数定为
 * inline类型。
 */
namespace AnsOne {
    // Time: 20ms  Memory: 12.1MB
    class Solution {
    public:
        std::string reverseWords(std::string s) {
            if (s == "") return "";
            int l = 0, r = 0;
            for (int i = findPos(s, ' ', 0); ; i = findPos(s, ' ', i+1)) {
                r = i - 1;
                for ( ; l < r; ++l, --r)
                    if (s[l] != s[r])
                        std::swap(s[l], s[r]);
                l = i + 1;
                if (l > s.size()) break;
            }
            return s;
        }

    private:
        inline int findPos(const std::string &s, char c, int beg) {
            auto pos = s.find(c, beg);
            return (pos == std::string::npos) ? s.size() : pos;
        }
    };
}    

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << (new Solution())->reverseWords("Let's take LeetCode contest") 
              << std::endl;
    // Ans: "s'teL ekat edoCteeL tsetnoc"
    return EXIT_SUCCESS;
}
