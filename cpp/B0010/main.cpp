// URL    : https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
// Author : Modnar
// Date   : 2020/03/13

#include <bits/stdc++.h>

/* ************************* */

// Complexity: Time: O(n)  Memory: O(1)
// Time: 4ms(60.56%)  Memory: 7.3MB(100.00%)
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int first = 0, second = 1;
        for (int i = 1; i != n; ++i) {
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
    std::cout << solution->fib(2) << std::endl;
    // Ans: 1
    std::cout << solution->fib(5) << std::endl;
    // Ans: 5
    return EXIT_SUCCESS;
}
