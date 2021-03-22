// URL    : https://leetcode-cn.com/problems/number-of-1-bits/
// Author : Modnar
// Date   : 2021/03/22

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms Memory: 5.9MB
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= (n - 1);
            ++ans;
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, char *const argv[]) {
    return EXIT_SUCCESS;
}

