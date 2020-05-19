// URL    : https://leetcode-cn.com/problems/valid-palindrome-ii/
// Author : Modnar
// Date   : 2020/05/19
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/valid-palindrome-ii/solution/yan-zheng-hui-wen-zi-fu-chuan-ii-by-leetcode-solut/
// Time: 112ms(22.96%)  Memory: 20MB(100.00%)
class Solution {
public:
    bool validPalindrome(std::string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i, --j;
            } else {
                return (check(s, i, j-1) || check(s, i+1, j));
            }
        }
        return true;
    }

private:
    bool check(const std::string &s, int l, int r) {
        for (int i = l, j = r; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->validPalindrome("aba") << std::endl;
    // Ans: 1(true)
    std::cout << (new Solution())->validPalindrome("abca") << std::endl;
    // Ans: 1(true)
    return EXIT_SUCCESS;
}
