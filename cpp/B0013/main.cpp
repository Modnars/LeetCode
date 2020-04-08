// URL    : https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// Author : Modnar
// Date   : 2020/04/08
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Time: 0ms(100.00%)  Memory: 6.8MB(100.00%)
class Solution {

    int get(int x) {
        int res = 0;
        for ( ; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }

public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
                // 边界判断
                if (i-1 >= 0) vis[i][j] |= vis[i-1][j];
                if (j-1 >= 0) vis[i][j] |= vis[i][j-1];
                ans += vis[i][j];
            }
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->movingCount(2, 3, 1) << std::endl;
    // Ans: 3
    std::cout << (new Solution())->movingCount(3, 1, 0) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->movingCount(5, 4, 0) << std::endl;
    // Ans: 1
    return EXIT_SUCCESS;
}
