// URL    : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
// Author : Modnar
// Date   : 2020/02/20
// Thanks : Hao Chen(@github.com) LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

namespace {
    const int MAX_SIZE = 256;
}

// 使用std::vector来存储位置
// Time: 12ms  Memory: 10.7MB
class Solution {
public:
    int lengthOfLongestSubstring(const std::string &s) {
        std::vector<int> pos(MAX_SIZE, -1);
        int ans = 0, lastRepeatPos = -1;
        for (int i = 0; i != s.size(); ++i) {
            if (pos[s[i]] != -1 && pos[s[i]] > lastRepeatPos)
                lastRepeatPos = pos[s[i]];
            ans = (ans > i-lastRepeatPos) ? ans : i-lastRepeatPos;
            pos[s[i]] = i;
        }
        return ans;
    }
};

/* ************************* */

namespace AnsOne {
    // 使用std::map来存储位置
    // Time: 40ms  Memory: 10.9MB
    class Solution {
    public:
        int lengthOfLongestSubstring(const std::string &s) {
            std::map<char, int> pos;
            int lastRepeatPos = -1, ans = 0;
            for (int i = 0; i != s.size(); ++i) {
                if (pos.find(s[i]) != pos.end() && lastRepeatPos < pos[s[i]])
                    lastRepeatPos = pos[s[i]];
                ans = (ans > i-lastRepeatPos) ? ans : i-lastRepeatPos;
                pos[s[i]] = i;
            }
            return ans;
        }
    };
}

/**
 * 滑动窗口
 */
namespace AnsTwo {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 56ms(20.74%)  Memory: 15.8MB(14.55%)
    class Solution {
    public:
        int lengthOfLongestSubstring(const std::string &s) {
            int i = 0, j = 0, ans = 0, n = s.size();
            std::set<char> window;
            while (i < n && j < n) {
                if (window.find(s[j]) == window.end()) {
                    window.insert(s[j++]);
                    ans = std::max(ans, j - i);
                } else {
                    window.erase(s[i++]);
                }
            }
            return ans;
        }
    };
}

int main(int argc, char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::cout << (new Solution())->lengthOfLongestSubstring("abcabcbb") << std::endl;
    // Ans: 3
    std::cout << (new Solution())->lengthOfLongestSubstring("aa") << std::endl;
    // Ans: 1
    std::cout << (new Solution())->lengthOfLongestSubstring("pwwkew") << std::endl;
    // Ans: 3
    std::cout << (new Solution())->lengthOfLongestSubstring("abbca") << std::endl;
    // Ans: 3
    return 0;
}
