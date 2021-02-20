// URL    : https://leetcode-cn.com/problems/daily-temperatures/
// Author : Modnar
// Date   : 2020/06/11
// Thanks : https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/

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

// 暴力法
// 由于温度值是[30, 100]上的整数值，所以维护next数组记录温度i下一次出现的坐标。
// 这里需要注意下i的偏移。
namespace AnsOne {
    // Time: 128ms Memory: 37.4MB
    class Solution {
    public:
        std::vector<int> dailyTemperatures(std::vector<int> &T) {
            static const int MAX_IDX = 50000; // 用于初始化next
            static const int MAX_TEMP = 100; // 记录最高温度值
            static const int MIN_TEMP = 30; // 记录最低温度值
            std::vector<int> next(MAX_TEMP-MIN_TEMP+1, MAX_IDX);
            // 由于ans要求的是最近的一天，所以用MAX_IDX初始化，更新时取min即可
            std::vector<int> ans(T.size(), MAX_IDX);
            for (int i = T.size() - 1; i >= 0; --i) {
                for (int j = T[i] + 1; j <= 100; ++j) {
                    if (next[j-MIN_TEMP] != MAX_IDX) {
                        ans[i] = std::min(next[j-MIN_TEMP]-i, ans[i]);
                    }
                }
                if (ans[i] == MAX_IDX) {
                    ans[i] = 0;
                }
                next[T[i]-MIN_TEMP] = i;
            }
            return ans;
        }
    };
}

namespace AnsTwo {
    // Time: 64ms Memory: 38.7MB
    class Solution {
    public:
        std::vector<int> dailyTemperatures(std::vector<int> &T) {
            std::vector<int> ans(T.size(), 0);
            std::vector<int> min_stk;
            for (int i = 0; i < T.size(); ++i) {
                while (!min_stk.empty() && T[min_stk.back()] < T[i]) {
                    ans[min_stk.back()] = i - min_stk.back();
                    min_stk.pop_back();
                }
                min_stk.emplace_back(i);
            }
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    for (const auto &val : (new AnsTwo::Solution())->dailyTemperatures(temperatures))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
