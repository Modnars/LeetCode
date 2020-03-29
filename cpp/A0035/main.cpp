// URL    : https://leetcode-cn.com/problems/search-insert-position/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return l;
    }
};

/* ************************* */

/**
 * STL
 */
namespace AnsOne {
    // Time: 0ms(100.00%)  Memory: 6.5MB(100.00%)
    class Solution {
    public:
        int searchInsert(std::vector<int> &nums, int target) {
            return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {1, 3, 5, 6};
    std::cout << (new Solution())->searchInsert(nums, 5) << std::endl;
    // Ans: 2
    std::cout << (new Solution())->searchInsert(nums, 2) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->searchInsert(nums, 7) << std::endl;
    // Ans: 4
    std::cout << (new Solution())->searchInsert(nums, 0) << std::endl;
    // Ans: 0
    return EXIT_SUCCESS;
}
