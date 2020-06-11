// URL    : https://leetcode-cn.com/problems/daily-temperatures/
// Author : Modnar
// Date   : 2020/06/11

#include <bits/stdc++.h>

/* ************************* */

// Failed: TIME_OUT
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &T) {
        int len = T.size();
        std::vector<int> ans(len, 0);
        for (int i = 0; i < len-1; ++i)
            for (int j = i+1; j < len; ++j)
                if (T[i] < T[j]) {
                    ans[i] = j - i;
                    break;
                }
        return ans;
    }
};

/* ************************* */

namespace AnsOne {
    class Solution {
    public:
        std::vector<int> dailyTemperatures(std::vector<int> &T) {
            int len = T.size(), pos = len - 1;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    for (const auto &val : (new Solution())->dailyTemperatures(temperatures))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
