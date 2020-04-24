// URL    : https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// Author : Modnar
// Date   : 2020/04/24

#include <bits/stdc++.h>

/* ************************* */

// Failed: TIME_OUT
class Solution {
public:
    int reversePairs(std::vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int ans = 0;
        for (int i = 0; i < nums.size()-1; ++i)
            for (int j = nums.size()-1; j > i; --j)
                if (nums[j-1] > nums[j]) {
                    std::swap(nums[j-1], nums[j]);
                    ++ans;
                }
        return ans;
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/shu-zu-zhong-de-ni-xu-dui-by-leetcode-solution/
    // Time: 296ms(63.10%)  Memory: 44.6MB(100.00%)
    class Solution {
    public:
        int mergeSort(std::vector<int> &nums, std::vector<int> &tmp, int l, int r) {
            if (l >= r) {
                return 0;
            }
            int mid = (l + r) / 2;
            int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
            int i = l, j = mid + 1, pos = l;
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    tmp[pos] = nums[i];
                    ++i;
                    inv_count += (j - (mid + 1));
                } else {
                    tmp[pos] = nums[j];
                    ++j;
                }
                ++pos;
            }
            for (int k = i; k <= mid; ++k) {
                tmp[pos++] = nums[k];
                inv_count += (j - (mid + 1));
            }
            for (int k = j; k <= r; ++k) {
                tmp[pos++] = nums[k];
            }
            std::copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
            return inv_count;
        }

        int reversePairs(std::vector<int> &nums) {
            int n = nums.size();
            std::vector<int> tmp(n);
            return mergeSort(nums, tmp, 0, n - 1);
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {7, 5, 6, 4};
    std::cout << (new Solution())->reversePairs(nums) << std::endl;
    // Ans: 5
    for (const auto &val : nums)
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
