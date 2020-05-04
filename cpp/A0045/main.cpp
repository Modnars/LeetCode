// URL    : https://leetcode-cn.com/problems/jump-game-ii/
// Author : Modnar
// Date   : 2020/05/04
// Thanks : LeetCode(leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: LeetCode(leetcode.cn)
// Solution: https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
// Time: 8ms(94.56%)  Memory: 7.7MB(100.00%)
class Solution {
public:
    int jump(std::vector<int> &nums) {
        int maxPos = 0, step = 0, end = 0, len = nums.size();
        for (int i = 0; i < len-1; ++i) {
            if (maxPos >= i) {
                maxPos = std::max(maxPos, i+nums[i]);
                if (i == end) {
                    ++step;
                    end = maxPos;
                }
            }
        }
        return step;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << (new Solution())->jump(nums) << std::endl;
    // Ans: 2
    return EXIT_SUCCESS;
}
