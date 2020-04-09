// URL    : https://leetcode-cn.com/problems/generate-parentheses/
// Author : Modnar
// Date   : 2020/04/09
// Thanks : 负雪明烛(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Time: 12ms(31.83%) Memory: 16.5MB(59.74%)
// Thanks: 负雪明烛(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/generate-parentheses/solution/ru-men-ji-bie-de-hui-su-fa-xue-hui-tao-lu-miao-don/
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        int lc = 0, rc = 0;
        dfs(res, "", n, lc, rc);
        return res;
    }

private:
    void dfs(std::vector<std::string> &res, std::string path, int n, int lc, int rc) {
        if (rc > lc || lc > n || rc > n) return;
        if (lc == rc && lc == n) {
            res.emplace_back(path);
            return;
        }
        dfs(res, path+'(', n, lc+1, rc);
        dfs(res, path+')', n, lc, rc+1);
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    for (const auto &s: solution->generateParenthesis(3))
        std::cout << s << std::endl;
    return EXIT_SUCCESS;
}
