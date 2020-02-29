// URL    : https://leetcode-cn.com/problems/unique-paths/
// Author : Modnar
// Date   : 2020/02/29

#include <bits/stdc++.h>

/* ************************* */

/**
 * 组合数
 *     数学原理，其总路数为C(m+n-2, m-1)。
 */
// Time: 4ms(65.33%)  Memory: 8.4MB(47.68%)
class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination(m+n-2, m-1);
    }

private:
    static int combination(int n, int m) {
        std::vector<unsigned int> ans(2, 1);
        for (int i = 1; i < n; ++i) {
            ans.push_back(1);
            for (int j = std::min(i, m); j != 0; --j)
                ans[j] += ans[j-1];
        }
        return ans[m];
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->uniquePaths(3, 2) << std::endl;
    // Ans: 3
    std::cout << (new Solution())->uniquePaths(7, 3) << std::endl;
    // Ans: 28
    std::cout << (new Solution())->uniquePaths(1, 1) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->uniquePaths(1, 2) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->uniquePaths(2, 1) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->uniquePaths(36, 7) << std::endl;
    // Ans: 4496388
    std::cout << (new Solution())->uniquePaths(100, 1) << std::endl;
    // Ans: 1
    return EXIT_SUCCESS;
}
