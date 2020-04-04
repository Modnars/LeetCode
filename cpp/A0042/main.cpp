// URL    : https://leetcode-cn.com/problems/trapping-rain-water/
// Author : Modnar
// Date   : 2020/04/04
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/trapping-rain-water/
// Time: 8ms(68.64%)  Memory: 7.2MB(100.00%)
class Solution {
public:
    int trap(std::vector<int> &height) {
        int curr = 0, ans = 0, len = height.size();
        std::stack<int> stk;
        while (curr != len) {
            while (!stk.empty() && height[curr] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int dis = curr - stk.top() - 1;
                int bounded_height = 
                    std::min(height[curr], height[stk.top()]) - height[top];
                ans += dis * bounded_height;
            }
            stk.push(curr++);
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << (new Solution())->trap(nums) << std::endl;
    // Ans: 6
    return EXIT_SUCCESS;
}
