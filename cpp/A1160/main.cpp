// URL    : https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
// Author : Modnar
// Date   : 2020/03/17

#include <bits/stdc++.h>

using std::vector;
using std::string;

/* ************************* */

/**
 * 统计字典与字符使用情况，进行比较判断
 */
// Time: 76ms(61.63%)  Memory: 20.7MB(46.19%)
class Solution {
public:
    int countCharacters(std::vector<std::string> &words, std::string chars) {
        std::vector<int> dictionary(26, 0), usage(26, 0);
        int ans = 0;
        for (const char &ch : chars)
            ++dictionary[ch-'a'];
        for (const std::string &word : words) {
            bool found = true;
            usage = std::vector<int>(26, 0);
            for (const char &ch : word)
                ++usage[ch-'a'];
            for (const char &ch : word)
                if (dictionary[ch-'a'] < usage[ch-'a'])
                    found = false;
            if (found)
                ans += word.size();
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<std::string> words = {"cat", "bt", "hat", "tree"};
    std::cout << solution->countCharacters(words, "atach") << std::endl;
    // Ans: 6
    words = {"hello", "world", "leetcode"};
    std::cout << solution->countCharacters(words, "welldonehoneyr") << std::endl;
    // Ans: 10
    return EXIT_SUCCESS;
}
