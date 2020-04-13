// URL    : https://leetcode-cn.com/problems/super-egg-drop/
// Author : Modnar
// Date   : 2020/04/12
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution/
// Time: 440ms(10.37%) Memory: 21.7MB(50.00%)
class Solution {
    std::unordered_map<int, int> memo;

    int dp(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }
                ans = 1 + std::min(std::max(dp(K-1, lo-1), dp(K, N-lo)),
                        std::max(dp(K-1, hi-1), dp(K, N-hi)));
            }
            memo[N * 100 + K] = ans;
        }
        return memo[N * 100 + K];
    }

public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
