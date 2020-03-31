// URL    : https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Author : Modnar
// Date   : 2020/04/01
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/you-xiao-gua-hao-de-qian-tao-shen-du-by-leetcode-s/
// Time: 4ms(88.16%)  Memory: 7.8MB(100.00%)
class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans;
        int depth = 0;
        for (int i = 0; i != seq.size(); ++i)
            if (seq[i] == '(') {
                ans.emplace_back((depth++)%2);
            } else {
                ans.emplace_back((--depth)%2);
            }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    for (const auto &val : (new Solution())->maxDepthAfterSplit("()(())()"))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
