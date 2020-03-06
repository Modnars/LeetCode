// URL    : https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
// Author : Modnar
// Date   : 2020/03/06
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 使用通用方法: 用位运算异或即可。
 */
// Complexity: O(n)
// Time: 16ms(18.58%)  Memory: 12.9MB(5.62%)
class Solution {
public:
    int singleNonDuplicate(std::vector<int> &nums) {
        int ans = 0;
        for (const int &val : nums)
            ans ^= val;
        return ans;
    }
};

/* ************************* */

/**
 *     由于数组有序，可以检查奇数位置i的数值，若nums[i] != nums[i+1]，则可知nums[i]
 * 即为所求。
 *     需要注意的就是循环终点的判断。
 */
namespace AnsOne {
    // Complexity: O(n)
    // Time: 4ms(99.65%)  Memory: 12.9MB(5.62%)
    class Solution {
    public:
        int singleNonDuplicate(std::vector<int> &nums) {
            int i = 0;
            for ( ; i < nums.size()-1; i += 2)
                if (nums[i] != nums[i+1])
                    break;
            return nums[i];
        }
    };
}

namespace AnsTwo {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 12ms(58.94%)  Memory: 12.9MB(5.62%)
    class Solution {
    public:
        int singleNonDuplicate(std::vector<int> &nums) {
            int low = 0, high = nums.size()-1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (mid % 2) --mid;
                if (nums[mid] == nums[mid+1])
                    low = mid + 2;
                else
                    high = mid;
            }
            return nums[low];
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    std::cout << (new Solution())->singleNonDuplicate(nums) << std::endl;
    // Ans: 2
    nums = {3, 3, 7, 7, 10, 11, 11};
    std::cout << (new Solution())->singleNonDuplicate(nums) << std::endl;
    // Ans: 10
    nums = {3, 3, 7, 7, 11, 11, 12};
    std::cout << (new Solution())->singleNonDuplicate(nums) << std::endl;
    // Ans: 12
    nums = {1, 1, 2};
    std::cout << (new Solution())->singleNonDuplicate(nums) << std::endl;
    // Ans: 2
    nums = {1};
    std::cout << (new Solution())->singleNonDuplicate(nums) << std::endl;
    // Ans: 1
    return EXIT_SUCCESS;
}
