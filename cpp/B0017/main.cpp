// URL    : https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
// Author : Modnar
// Date   : 2020/03/24

#include <bits/stdc++.h>

/* ************************* */

// Time: 12ms(53.78%)  Memory: 10.4MB(100.00%)
class Solution {
public:
    std::vector<int> printNumbers(int n) {
        int sz = std::pow(10, n);
        std::vector<int> ans(sz-1);
        for (int i = 1; i != sz; ++i)
            ans[i-1] = i;
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    for (const int &val : (new Solution())->printNumbers(1))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
