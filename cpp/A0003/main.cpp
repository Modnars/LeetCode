// URL    : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
// Author : Modnar
// Date   : 2020/02/20
// Thanks : Hao Chen

#include <map>
#include <string>
#include <vector>
#include <iostream>

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
            // ans = std::max(ans, i-lastRepeatPos);
            ans = (ans > i-lastRepeatPos) ? ans : i-lastRepeatPos;
            pos[s[i]] = i;
        }
        return ans;
    }
//    int lengthOfLongestSubstring(const std::string &s) {
//        std::vector<int> pos(MAX_SIZE, -1);
//        int ans = 0;
//        for (int i = 0; i != s.size(); ++i) {
//            if (pos[s[i]] == -1) {
//                ++ans;
//                pos[s[i]] = i;
//            } else {
//                ans = (i - pos[s[i]]) > ans ? (i - pos[s[i]]) : ans;
//                pos[s[i]] = i;
//            }
//        }
//        return ans;
//    }
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

int main(int argc, char *argv[]) {
    using Solution = AnsOne::Solution;
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
