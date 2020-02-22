// URL    : https://leetcode-cn.com/problems/longest-common-prefix/
// Author : Modnar
// Date   : 2020/02/22
// Thanks : 画解算法(@leetcode.cn), xshura(@leetcode.cn)

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

/* ************************* */

// Time: 8ms  Memory: 11.4MB
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        if (strs.size() == 0) return "";
        int maxLen = 1;
        for ( ; ; ++maxLen) {
            if (maxLen > strs[0].size())
                return strs[0];
            std::string prefix = strs[0].substr(0, maxLen);
            for (std::string &s : strs)
                if (s.size() < maxLen || s.find(prefix) != 0)
                    return strs[0].substr(0, maxLen-1);
        }
        return strs[0].substr(0, maxLen-1);
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks : 画解算法(@leetcode.cn)
    // Time: 8ms  Memory: 11.5MB
    class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string> &strs) {
            if (strs.size() == 0) return "";
            std::string ans = strs[0];
            for (int i = 1; i != strs.size(); ++i) {
                int j = 0;
                for ( ; j != ans.size() && j != strs[i].size(); ++j)
                    if (ans[j] != strs[i][j])
                        break;
                ans = ans.substr(0, j);
                if (ans == "") return "";
            }
            return ans;
        }
    };
}

namespace AnsTwo {
    // Thanks: LGH(@leetcode.cn)
    // Time: 8ms  Memory: 11.3MB
    class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string> &strs) {
            if (strs.size() == 0) return "";
            int len = strs[0].size();
            for (int i = 1; i < strs.size(); ++i)
                len = strs[i].size() < len ? strs[i].size() : len;
            std::string ans;
            char ch;
            for (int i = 0; i < len; ++i) {
                ch = strs[0][i];
                for (const auto &s : strs) 
                    if (s[i] != ch)
                        return ans;
                ans += ch;
            }
            return ans;
        }
    };
}

/**
 * 利用字符串可比较大小的性质来求解
 *     考虑到字符串其实也是可以比较大小的，那么就选出vector中最小的字符串和vector中
 * 最大的字符串，理论上来说，这两个字符串应该是“差异”最大的。这时求这二者间的最长公共
 * 前缀即可。
 */
namespace AnsThree {
    // Thanks: xshura(@leetcode.cn)
    // Time: 12ms  Memory: 11.6MB
    class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string> &strs) {
            if (strs.size() == 0) return "";
            std::string max_ans = strs[0], min_ans = strs[0];
            for (const auto &s : strs) {
                min_ans = s < min_ans ? s : min_ans;
                max_ans = s > max_ans ? s : max_ans;
            }
            std::string ans = "";
            for (int i = 0; i != min_ans.size() && i != max_ans.size(); ++i) {
                if (min_ans[i] != max_ans[i])
                    return ans;
                ans += min_ans[i];
            }
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << (new Solution())->longestCommonPrefix(strs) << std::endl;
    // Ans: "fl"
    strs = {"dog", "racecar", "car"};
    std::cout << (new Solution())->longestCommonPrefix(strs) << std::endl;
    // Ans: ""
    strs = {"aa", "a"};
    std::cout << (new Solution())->longestCommonPrefix(strs) << std::endl;
    // Ans: "a"
    return EXIT_SUCCESS;
}
