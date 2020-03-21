// URL    : https://leetcode-cn.com/problems/water-and-jug-problem/
// Author : Modnar
// Date   : 2020/03/21
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

using PII = std::pair<int, int>;

// Thanks: LeetCode(@leetcode.cn)
// Time: 1628ms(5.97%)  Memory: 308.2MB(5.43%)
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        std::stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) {return std::hash<int>()(o.first) ^ std::hash<int>()(o.second);};
        std::unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());
            
            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            // 把 X 壶灌满。
            stk.emplace(x, remain_y);
            // 把 Y 壶灌满。
            stk.emplace(remain_x, y);
            // 把 X 壶倒空。
            stk.emplace(0, remain_y);
            // 把 Y 壶倒空。
            stk.emplace(remain_x, 0);
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(remain_x - std::min(remain_x, y - remain_y), remain_y + std::min(remain_x, y - remain_y));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(remain_x + std::min(remain_y, x - remain_x), remain_y - std::min(remain_y, x - remain_x));
        }
        return false;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
