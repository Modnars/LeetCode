// URL    : https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
// Author : Modnar
// Date   : 2020/03/14

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms(61.46%)  Memory: 7.3MB(100.00%)
class Solution {
public:
    int numWays(int n) {
        int first = 0, second = 1;
        for (int i = 0; i != n; ++i) {
            int sum = (first + second) % MOLD;
            first = second;
            second = sum;
        }
        return second;
    }

private:
    static const int MOLD;
};

const int Solution::MOLD = 1e9 + 7;

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::cout << solution->numWays(2) << std::endl;
    // Ans: 2
    std::cout << solution->numWays(7) << std::endl;
    // Ans: 21
    return EXIT_SUCCESS;
}
