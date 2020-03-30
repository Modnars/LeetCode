// URL    : https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
// Author : Modnar
// Date   : 2020/03/30
// Thanks : Sweetiee🍬的小号(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks:  Sweetiee🍬的小号(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/
// Time: 4ms(100.00%)  Memory: 5.6MB(100.00%)
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; ++i)
            ans = (ans + m) % i;
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    const int &a = 1;
    std::cout << a << std::endl;
    return EXIT_SUCCESS;
}
