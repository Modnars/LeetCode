// URL    : https://leetcode-cn.com/problems/bulb-switcher/
// Author : Modnar
// Date   : 2020/03/11
// Thanks : 井水(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Failed: TIME_OUT
class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0) return 0;
        std::vector<bool> status(n+1, true);
        for (int i = 2; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                status[j] = !status[j];
        return static_cast<int>(std::accumulate(status.begin()+1, status.end(), 0));
    }
};

/* ************************* */

/**
 *  1: 1                    1
 *  2: 1 0                  1
 *  3: 1 0 0                1
 *  4: 1 0 0 1              2
 *  5: 1 0 0 1 0            2
 *  6: 1 0 0 1 0 0          2
 *  7: 1 0 0 1 0 0 0        2
 *  8: 1 0 0 1 0 0 0 0      2
 *  9: 1 0 0 1 0 0 0 0 1    3
 *
 * 规律就是: 每隔奇数个数值，答案加一，且奇数值递增。
 */
namespace AnsOne {
    // Time: 0ms(100.00%)  Memory: 7.4MB(100.00%)
    class Solution {
    public:
        int bulbSwitch(int n) {
            int ans = 0, sum = 0;
            for (int i = 3; sum < n; i += 2) {
                sum += i;
                ++ans;
            }
            return ans;
        }
    };
}

/**
 * 平方数位置的灯一定是亮着的。
 */
namespace AnsTwo {
    // Thanks: 井水(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/bulb-switcher/solution/wei-shi-yao-ping-fang-shu-yi-ding-shi-liang-zhao-d/
    // Time: 0ms(100.00%)  Memory: 7.6MB(100.00%)
    class Solution {
    public:
        int bulbSwitch(int n) {
            return static_cast<int>(std::sqrt(n));
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    for (int i = 1; i != 40; ++i)
        std::cout << solution->bulbSwitch(i) << std::endl;
    return EXIT_SUCCESS;
}
