// URL    : https://leetcode-cn.com/problems/chou-shu-lcof/
// Author : Modnar
// Date   : 2020/03/22

#include <bits/stdc++.h>

/* ************************* */

// Time: 44ms(12.63%)  Memory: 19.8MB(100.00%)
class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<std::queue<long long>> candicate(3, std::queue<long long>());
        std::queue<long long> store;
        store.push(1);
        long long ans = 0;
        for (int i = 0; i != n; ++i) {
            ans = store.front(); store.pop();
            candicate[0].push(ans*2); // 2, 4, 6, 8, 10, 12, ...
            candicate[1].push(ans*3); // 3, 6, 9, 12, 15, 18, ...
            candicate[2].push(ans*5); // 5, 10, 15, 20, 25, 30, ...
            long long next = std::min(candicate[0].front(), 
                    std::min(candicate[1].front(), candicate[2].front()));
            for (int i = 0; i != 3; ++i)
                if (candicate[i].front() == next)
                    candicate[i].pop();
            store.push(next);
        }
        return ans;
    }
};

/* ************************* */

/**
 * 动态规划
 *
 * 一个十分巧妙的动态规划问题
 *     1.我们将前面求得的丑数记录下来，后面的丑数就是前面的丑数*2，*3，*5
 *     2.但是问题来了，我怎么确定已知前面k-1个丑数，我怎么确定第k个丑数呢
 *     3.采取用三个指针的方法，p2,p3,p5
 *     4.index2指向的数字下一次永远*2，p3指向的数字下一次永远*3，p5指向的数字永远*5
 *     5.我们从2*p2 3*p3 5*p5选取最小的一个数字，作为第k个丑数
 *     6.如果第K个丑数==2*p2，也就是说前面0-p2个丑数*2不可能产生比第K个丑数更大的丑数
 * 了，所以p2++
 *     7.p3,p5同理
 *     8.返回第n个丑数
 *
 *     这个算法相对于默认解的优势在于“延迟计算”，本算法只是记录了p2, p3, p5的下标，而
 * 在真正需要添加的时候才进行计算，而不是先计算出需添加的元素而直接添加到队列中。这样
 * 的好处在于避免了大量的无用计算与比较，是对默认解的极大优化。
 */
namespace AnsOne {
    // Thanks: 斩钉(@leetcode.cn)
    // Time: 4ms(97.47%)  Memory: 9MB(100.00%)
    class Solution {
    public:
        int nthUglyNumber(int n) {
            std::vector<int> dp(n, 1);
            int p2 = 0, p3 = 0, p5 = 0;
            for (int i = 1; i != n; ++i) {
                dp[i] = std::min(dp[p2]*2, std::min(dp[p3]*3, dp[p5]*5));
                if (dp[i] == dp[p2]*2) ++p2;
                if (dp[i] == dp[p3]*3) ++p3;
                if (dp[i] == dp[p5]*5) ++p5;
            }
            return dp[n-1];
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    std::cout << solution->nthUglyNumber(10) << std::endl;
    // Ans: 12
    std::cout << solution->nthUglyNumber(1690) << std::endl;
    // Ans: 2123366400
    return EXIT_SUCCESS;
}
