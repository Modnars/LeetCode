// URL    : https://leetcode-cn.com/problems/compress-string-lcci/
// Author : Modnar
// Date   : 2020/03/16

#include <bits/stdc++.h>

/* ************************* */

// Time: 12ms(86.17%)  Memory: 8.6MB(100.00%)
class Solution {
public:
    std::string compressString(std::string S) {
        if (S.size() == 0) return "";
        std::string ans;
        char character = S[0];
        int count = 1;
        for (int i = 1; i != S.size(); ++i)
            if (S[i] == character) {
                ++count;
            } else {
                ans += character + std::to_string(count);
                character = S[i];
                count = 1;
            }
        ans += character + std::to_string(count);
        return (ans.size() < S.size()) ? ans : S;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::cout << solution->compressString("aabcccccaa") << std::endl;
    // Ans: "a2b1c5a2"
    std::cout << solution->compressString("abbccd") << std::endl;
    // Ans: "abbccd"
    return EXIT_SUCCESS;
}
