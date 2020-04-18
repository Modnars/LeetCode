// URL    : https://leetcode-cn.com/problems/jump-game/
// Author : Modnar
// Date   : 2020/04/18
// Thanks : 明天更要加油啊(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Failed: TIME_OUT
class Solution {
public:
    bool canJump(std::vector<int> &nums) {
        ans = false;
        std::vector<bool> used(nums.size(), false);
        backtrack(nums, used, 0, nums.size()-1);
        return ans;
    }

private:
    void backtrack(std::vector<int> &nums, std::vector<bool> &used, int pos, int endpos) {
        if (pos >= endpos) {
            ans = true;
            return;
        }
        for (int i = nums[pos]; i >= 0 && !used[pos]; --i) {
            used[pos] = true;
            backtrack(nums, used, pos+i, endpos);
            used[pos] = false;
        }
    }
    bool ans = false;
};

namespace AnsOne {
    // Time: 12ms(71.19%)  Memory: 7.7MB(100.00%)
    // Thanks: 明天更要加油啊(@leetcode.cn)
    class Solution {
    public:
        bool canJump(std::vector<int> &nums) {
            int can_reach = 0;
            for (int i = 0; i != nums.size(); ++i) {
                if (i > can_reach) return false;
                can_reach = std::max(can_reach, i+nums[i]);
            }
            return true;
        }
    };
}

/* ************************* */

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << (new Solution())->canJump(nums) << std::endl;
    // Ans: 1(true)
    nums = {3, 2, 1, 0, 4};
    std::cout << (new Solution())->canJump(nums) << std::endl;
    // Ans: 0(true)
    return EXIT_SUCCESS;
}
