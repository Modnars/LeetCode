// File:   A0003/main.cc
// Author: modnarshen
// Date:   2022.08.03

#include <bits/stdc++.h>

// 找当前字符与最后一个重复出现的字符之间的距离，这个距离的最大值就是ans
class Solution {
public:
    int lengthOfLongestSubstring(const std::string &s) {
        std::unordered_map<int8_t, int> last_pos;
        int max_len  = 0;
        int last_idx = 0;
        for (int i = 1; i <= static_cast<int>(s.size()); ++i) {
            last_idx           = std::max(last_idx, last_pos[s[i - 1]]);
            max_len            = std::max(max_len, i - last_idx);
            last_pos[s[i - 1]] = i;
        }
        return max_len;
    }
};

int main(int argc, const char *argv[]) {
    auto *solution = new Solution();
    std::cout << solution->lengthOfLongestSubstring("abcabcbb") << std::endl; // 3
    std::cout << solution->lengthOfLongestSubstring("bbbbb") << std::endl;    // 1
    std::cout << solution->lengthOfLongestSubstring("pwwkew") << std::endl;   // 3
    return 0;
}
