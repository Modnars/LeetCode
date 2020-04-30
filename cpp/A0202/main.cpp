// URL    : https://leetcode-cn.com/problems/happy-number/
// Author : Modnar
// Date   : 2020/04/30

#include <bits/stdc++.h>

/* ************************* */

/**
 * 使用一个Set来存储计算过的数字。当发现Set中已经出现过该数字，判断该数字是否为1即可。
 */
class Solution {
public:
    bool isHappy(int n) {
        std::set<int> check;
        int ans = process(n);
        while (check.find(ans) == check.end()) {
            check.insert(ans);
            ans = process(ans);
        }
        return ans == 1;
    }

private:
    int process(int n) {
        int val = 0;
        while (n) {
            val += (n % 10) * (n % 10);
            n = n / 10;
        }
        return val;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    for (int i = 1; i != 101; ++i) {
        std::cout << i << ": " << (solution->isHappy(i) ? "True" : "False") 
                  << std::endl;
    }
    return EXIT_SUCCESS;
}
