// URL    : https://leetcode-cn.com/problems/group-anagrams/
// Author : Modnar
// Date   : 2020/03/15

#include <bits/stdc++.h>

using std::string;

/* ************************* */

/**
 *     将字符串排序后的结果作为哈希表索引，存储所有相同排序结果的串到一个数组中，并将
 * 所有数组合成并返回。
 */
// Thanks: LeetCode(@leetcode.cn)
// Time: 48ms(70.34%)  Memory: 21MB(16.51%)
class Solution {
public:
    std::vector<std::vector<string>> groupAnagrams(std::vector<string> &strs) {
        std::map<std::string, std::vector<std::string>> store;
        std::vector<std::vector<std::string>> ans;
        if (strs.size() == 0) return ans;
        int i = 0;
        for (std::string s : strs) {
            std::sort(s.begin(), s.end());
            store[s].emplace_back(strs[i]);
            ++i;
        }
        for (auto item : store)
            ans.emplace_back(item.second);
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (const auto &row : solution->groupAnagrams(strs)) {
        for (const auto &s : row)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    // std::cout << solution->equals("eat", "tea") << std::endl;
    // std::string s = "eat";
    // std::sort(s.begin(), s.end());
    // std::cout << s << std::endl;
    return EXIT_SUCCESS;
}
