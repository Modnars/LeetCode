// URL    : https://leetcode-cn.com/problems/valid-palindrome/
// Author : Modnar
// Date   : 2020/05/19

#include <bits/stdc++.h>

/* ************************* */

/**
 * 双指针:
 *     使用i、j两个指针，分别从字符串头尾进行遍历，因而整个算法时间复杂度为O(n)。
 *     当遍历的字符不是字母或数字时，自动跳过即可。需要注意的就是遍历指针是否越界。
 */
// Time: 8ms(85.10%)  Memory: 7.2MB(100.00%)
class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.size() == 0)
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < s.size() && !isalpha(s[i]) && !isdigit(s[i])) ++i;
            while (j >= 0 && !isalpha(s[j]) && !isdigit(s[j])) --j;
            if (i < j) {
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                ++i, --j;
            }
        }
        return true;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->isPalindrome("A man, a plan, a canal: Panama")
              << std::endl;
    // Ans: 1(true)
    std::cout << (new Solution())->isPalindrome("race a car")
              << std::endl;
    // Ans: 0(false)
    std::cout << (new Solution())->isPalindrome(".,")
              << std::endl;
    // Ans: 1(true)
    std::cout << (new Solution())->isPalindrome("0P")
              << std::endl;
    // Ans: 0(false)
    return EXIT_SUCCESS;
}
