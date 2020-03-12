// URL    : https://leetcode-cn.com/problems/count-and-say/
// Author : Modnar
// Date   : 2020/03/11

#include <bits/stdc++.h>

/* ************************* */

// Time: 0ms(100.00%)  Memory: 8.8MB(50.77%)
class Solution {
public:
    std::string countAndSay(int n) {
        std::string ans = "1";
        while (--n) {
            int count = 1;
            char ch = ans[0];
            std::string res = "";
            for (int i = 1; i != ans.size(); ++i) {
                if (ch == ans[i]) {
                    ++count;
                } else {
                    res += std::to_string(count);
                    res += ch;
                    ch = ans[i];
                    count = 1;
                }
            }
            res += std::to_string(count);
            res += ch;
            ans = res;
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    for (int i = 1; i != 10; ++i)
        std::cout << solution->countAndSay(i) << std::endl;
    return EXIT_SUCCESS;
}
