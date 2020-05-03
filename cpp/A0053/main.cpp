// URL    : https://leetcode-cn.com/problems/maximum-subarray/
// Author : Modnar
// Date   : 2020/02/26

// ✅ : 2020/05/03

#include <bits/stdc++.h>

/* ************************* */

// Complexity: O(n^3)
// Failed: TIMEOUT
class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        int ans = INT_MIN;
        for (int i = 0; i != nums.size(); ++i)
            for (int j = i+1; j != nums.size()+1; ++j) {
                int sum = 0;
                for (int k = i; k != j; ++k)
                    sum += nums[k];
                ans = sum > ans ? sum : ans;
            }
        return ans;
    }
};

/* ************************* */

/**
 * 贪心算法
 *     在从头到尾遍历过程中，维护curr_sum来计算当前位置的子序列最大和；用max_sum来记录
 * 整个数组在遍历过程中的子序列最大和。
 *     二者的区别在于，curr_sum的值总是随着位置动态更新的，其更新只观察两种情况(见代
 * 码)，而max_sum则是根据所有的curr_sum来决定的。
 *     可能乍一看不太好理解，建议结合代码进行理解。
 */
namespace AnsOne {
    // Complexity: Time: O(n)  Memory: O(1)
    // Time: 16ms(18.48%)  Memory: 15.3MB(5.14%)
    class Solution {
    public:
        int maxSubArray(std::vector<int> &nums) {
            int curr_sum = nums[0], max_sum = nums[0];
            for (int i = 1; i != nums.size(); ++i) {
                // 确定当前位置最大值: 
                //   1. 上个位置的curr_sum和当前位置值的和更大
                //   2. 当前位置单独的值更大
                curr_sum = std::max(curr_sum+nums[i], nums[i]); 
                // 记录遍历过程中的最大值
                max_sum = std::max(max_sum, curr_sum);
            }
            return max_sum;
        }
    };
}

/**
 * 分治法
 */
namespace AnsTwo {
    // Time: 20ms(12.54%)  Memory: 15.7MB(5.14%)
    class Solution {
    public:
        int maxSubArray(std::vector<int> &nums) {
            return helper(nums, 0, nums.size()-1);
        }

    private:
        int crossSum(const std::vector<int> &nums, int left, int right, int p) {
            if (left == right) return nums[left];
            int leftSubSum = INT_MIN;
            int curr_sum = 0;
            for (int i = p; i > left-1; --i) {
                curr_sum += nums[i];
                leftSubSum = std::max(leftSubSum, curr_sum); 
            }
            int rightSubSum = 0;
            curr_sum = 0;
            for (int i = p+1; i < right+1; ++i) {
                curr_sum += nums[i];
                rightSubSum = std::max(rightSubSum, curr_sum);
            }
            return leftSubSum + rightSubSum;
        }

        int helper(const std::vector<int> &nums, int left, int right) {
            if (left == right) return nums[left];
            int p = (left + right) / 2;
            int leftSum = helper(nums, left, p);
            int rightSum = helper(nums, p+1, right);
            int crossSum = this->crossSum(nums, left, right, p);
            return std::max(crossSum, std::max(leftSum, rightSum));
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << (new Solution())->maxSubArray(nums) << std::endl;
    // Ans: 6
    return EXIT_SUCCESS;
}
