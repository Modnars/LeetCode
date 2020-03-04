// URL    : https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// Author : Modnar
// Date   : 2020/03/04

#include <bits/stdc++.h>

/* ************************* */

/**
 * 循环拷贝加后缀
 *     当ans中已经存在len个前缀后，当遍历到digits[i]时，设digits[i]对应的所有字符有n
 * 个，那么将已有的ans的所有内容拷贝n-1遍并加入至ans尾端。然后对每len个前缀后加上当前
 * 需添加的字符。
 *     举例来说：当输入串为"23"时。令ans先存入""，保证其长度(len)为1。
 *     ‘2’对应的串为”abc“，那么将ans中的""拷贝三遍，此时ans={"", "", ""}，再将每个字符
 * 加入，得到此时的ans={"a", "b", "c"}，len = 3;
 *     ‘3’对应的串为“def”，那么将ans中的内容拷贝三遍，此时
 *           ans = {"a", "b", "c", "a", "b", "c", "a", "b", "c"};
 *     再对每len个前缀后加上当前需添加的字符：
 *           ans = {"ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"};
 *     即得到最终答案。
 */
// Time: 4ms(69.73%)  Memory: 9MB(7.86%)
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ans;
        if (!digits.size()) return ans;
        ans.push_back("");
        for (int i = 0 ; i != digits.size(); ++i) {
            if (digits[i] == '1') continue;
            char number = digits[i];
            const std::string &characters = keyboard.find(number)->second;
            int len = ans.size();
            // 这种写法，LeetCode运行结果不正常，而本地结果符合预期。
            // for (int j = 0; j != characters.size()-1; ++j) {
            //     ans.insert(ans.end(), ans.begin(), ans.begin()+len);
            // }
            for (int j = 0; j != characters.size()-1; ++j)
                for (int k = 0; k != len; ++k)
                    ans.push_back(ans[k]);
            for (int j = 0; j != characters.size(); ++j) {
                int offset = j * len;
                char append = characters[j];
                for (int k = 0; k != len; ++k)
                    ans[offset+k] += append;
            }
        }
        return ans;
    }

private:
    static const std::map<char, std::string> keyboard;
};

const std::map<char, std::string> Solution::keyboard = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

/* ************************* */

int main(int argc, const char *argv[]) {
    for (const auto numbers : (new Solution())->letterCombinations("23"))
        std::cout << numbers << std::endl;
    return EXIT_SUCCESS;
}
