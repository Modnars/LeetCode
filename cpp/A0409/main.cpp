// URL    : https://leetcode-cn.com/problems/longest-palindrome/
// Author : Modnar
// Date   : 2020/03/19

#include <bits/stdc++.h>

/* ************************* */

/**
 *     对于一个回文串，按题目要求，对于出现次数值为奇数的字符，最终结果加上该字符出现
 * 次数值减1(比如a出现3次，则最长回文串一定至少用到两个a)；对于出现次数值为偶数的字
 * 符，直接在长度值上添加该次数值。当然，如果在给定字符集中确实出现了次数值为奇数的字
 * 符，要在最终答案上添加1，以此来构建最长长度为奇数回文串。
 */
// Time: 0ms(100.00%)  Memory: 8.2MB(100.00%)
class Solution {
public:
    int longestPalindrome(std::string s) {
        std::vector<int> store(52, 0);
        int ans = 0, single = 0, append = 0;
        for (const char &ch : s)
            ++store[pos(ch)];
        for (int i = 0; i != store.size(); ++i) {
            if (store[i] % 2) {
                single += store[i] - 1;
                append = 1;
            } else {
                ans += store[i];
            }
        }
        ans += single;
        ans += append;
        return ans;
    }

private:
    // 要求输入的ch一定是大小写字母
    int pos(const char &ch) {
        if (ch >= 'a' && ch <= 'z')
            return ch - 'a';
        return 26 + ch - 'A';
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->longestPalindrome("abccccdd") << std::endl;
    // Ans: 7
    std::cout << (new Solution())->longestPalindrome("ccc") << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
