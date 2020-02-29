// URL    : https://leetcode-cn.com/problems/3sum-closest/
// Author : Modnar
// Date   : 2020/02/29

#include <bits/stdc++.h>

/* ************************* */

// Complexity: Time: O(n^2)  Space: O(1)
// Time: 12ms(58.73%)  Memory: 12.2MB(5.44%)
class Solution {
public:
    int threeSumClosest(std::vector<int> &nums, int target) {
        int len = nums.size(), ans = 0;
        if (len < 3) {
            for (const int &val : nums)
                ans += val;
            return ans;
        }
        std::sort(nums.begin(), nums.end());
        ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i-1]) continue;
            int val = nums[i];
            for (int j = i+1, k = nums.size()-1; j < k; ) {
                int sum = val + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
                ans = (std::abs(sum-target) < std::abs(ans-target)) ? sum : ans;
            }
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {-1, 2, 1, -4};
    std::cout << (new Solution())->threeSumClosest(nums, 1) << std::endl;
    // Ans: 2
    return EXIT_SUCCESS;
}
