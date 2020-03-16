// URL    : https://leetcode-cn.com/problems/length-of-last-word/
// Author : Modnar
// Date   : 2020/03/16

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms(77.74%)  Memory: 8.2MB(100.00%)
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if (s.size() == 0) return 0;
        while (s.back() == ' ')
            s.pop_back();
        auto pos = s.find_last_of(' ');
        if (pos == std::string::npos)
            return s.size();
        else
            return s.size() - pos - 1;
        return 0;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::cout << solution->lengthOfLastWord("hello World") << std::endl;
    // Ans: 5
    std::cout << solution->lengthOfLastWord("World") << std::endl;
    // Ans: 5
    std::cout << solution->lengthOfLastWord("") << std::endl;
    // Ans: 0
    std::cout << solution->lengthOfLastWord("a") << std::endl;
    // Ans: 1
    std::cout << solution->lengthOfLastWord("a ") << std::endl;
    // Ans: 1
    return EXIT_SUCCESS;
}
