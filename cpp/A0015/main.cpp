// URL    : https://leetcode-cn.com/problems/3sum/
// Author : Modnar
// Date   : 2020/02/29
// Thanks : 吴彦祖(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: 吴彦祖(@leetcode.cn)
// Complexity: Time: O(n^2)  Memory: O(1)
// Time: 76ms(73.36%)  Memory: 22MB(5.04%)
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> ans;
        if (nums.size() < 3) return ans;
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0) return ans; // 如果最小值大于零，则数组中不存在满足条件的解
        for (int i = 0; i != nums.size(); ++i) {
            if (i && nums[i] == nums[i-1]) continue;
            int val = nums[i];
            for (int j = i+1, k = nums.size()-1; j < k; ) {
                int sum = val + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back(std::vector<int>{val, nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1])
                        ++j;
                    while (j < k && nums[k] == nums[k-1])
                        --k;
                    ++j; --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    for (const auto &row : (new Solution())->threeSum(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    // Ans:
    //   -1 -1  2
    //   -1  0  1
    std::cout << std::endl;
    nums = {3, 0, -2, -1, 1, 2};
    for (const auto &row : (new Solution())->threeSum(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    // Ans:
    //   -2 -1  3
    //   -2  0  2
    //   -1  0  1
    std::cout << std::endl;
    nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    for (const auto &row : (new Solution())->threeSum(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    // Ans:
    // [[-4, -2, 6], [-4, 0, 4], [-4, 1, 3], [-4, 2, 2], [-2, -2, 4], [-2, 0, 2]]
    return EXIT_SUCCESS;
}
