// URL    : https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
// Author : Modnar
// Date   : 2020/03/24

#include <bits/stdc++.h>

/* ************************* */

// Time: 0ms(100.00%)  Memory: 5.8MB(100.00%)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n & 1; // if (n & 1) ++ans;
            n >>= 1;
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    uint32_t n = 0b00000000000000000000000000001011;
    std::cout << (new Solution())->hammingWeight(n) << std::endl;
    // Ans: 3
    n = 0b00000000000000000000000010000000;
    std::cout << (new Solution())->hammingWeight(n) << std::endl;
    // Ans: 1
    n = 0b11111111111111111111111111111101;
    std::cout << (new Solution())->hammingWeight(n) << std::endl;
    // Ans: 31
    return EXIT_SUCCESS;
}
