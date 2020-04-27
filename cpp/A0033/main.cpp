// URL    : https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// Author : Modnar
// Date   : 2020/02/29
// Thanks : LeetCode(@leetcode.cn)

// ✅ : 2020/04/27

#include <bits/stdc++.h>

/* ************************* */

/**
 *     使用辅助vector缓存nums有序序列，记录有序偏移offset，然后对这个有序序列进行二分
 * 查找。对二分查找结果进行分析并按题目要求返回。
 */
// Complexity: Time: O(n)  Space: O(n)
// Time: 4ms(89.70%)  Memory: 13.8MB(5.14%)
class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        int len = nums.size(), offset = 0;
        if (len == 0) return -1;
        for (int i = 1; i != len; ++i)
            if (nums[i] < nums[i-1]) {
                offset = i;
                break;
            }
        std::vector<int> cache(nums.begin(), nums.begin()+offset);
        cache.insert(cache.begin(), nums.begin()+offset, nums.end());
        // for (const auto &val : cache)
        //     std::cout << val << " ";
        // std::cout << std::endl;
        int res = bin_search(cache, target);
        return (res < 0) ? -1 : (res + offset) % len;
    }

private:
    int bin_search(const std::vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

/* ************************* */

/**
 * 局部二分查找
 *     找到offset，对[0, offset)和[offset, nums.size-1]两部分使用局部二分搜索即可。
 *     其中，offset是nums中最小值(按题目要求来说)的下标。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: Time: O(logn) Space: O(1)
    // Time: 4ms(80.04%)  Memory: 6.4MB(100.00%)
    class Solution {
    public:
        int search(std::vector<int> &nums, int target) {
            int len = nums.size(), offset = 0;
            if (len == 0) return -1;
            for (int i = 1; i != len; ++i)
                if (nums[i] < nums[i-1]) {
                    offset = i;
                    break;
                }
            int res = bin_search(nums, target, 0, offset-1);
            return (res >= 0) ? res : bin_search(nums, target, offset, nums.size()-1);
        }

    private:
        int bin_search(const std::vector<int> &nums, int target, int low, int high) {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] < target) {
                    low = mid + 1;
                } else if (nums[mid] > target) {
                    high = mid - 1;
                } else {
                    return mid;
                }
            }
            return -1;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << (new Solution())->search(nums, 0) << std::endl;
    // Ans: 4
    nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << (new Solution())->search(nums, 3) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
