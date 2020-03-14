// URL    : https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
// Author : Modnar
// Date   : 2020/03/14
// Thanks : armeria(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 暴力搜索
 *     直接遍历，获取最小元素即可。
 *     本题存在一个简单优化，当发现某两个值之间发生“递减”，则可直接返回最小值。
 */
// Complexity: Time: O(n)  Space: O(1)
// Time: 8ms(44.19%)  Memory: 11.5MB(5.04%)
class Solution {
public:
    int findMin(std::vector<int> &nums) {
        // 本题不存在nums为空的情况，故此处可免去判断以加速
        int min_val = nums[0];
        for (int i = 0; i != nums.size(); ++i)
            if (nums[i] < min_val)
                return nums[i];
        return min_val;
    }
};

/* ************************* */

/**
 * 二分搜索
 *     充分利用题中所提到的数组元素不重复，这样，对于任意两个元素均可进行“偏序比较”。
 * 首先需要明确以下几点：二分过程中，左右端点值为l、r，中间值为mid。如果nums[mid] >
 * nums[r]，说明最小值一定在右半部分(相对mid来说)；否则(nums[mid] < nums[r])，就说明
 * 最小值一定在左半部分(相对mid来说)。
 *     细分来说，思考以下方面：
 *     1. 循环条件l < r，且l <= mid，mid更贴近l，而mid < r;
 *     2. 在while循环内，nums[mid]要么小于nums[r]，要么大于，而不会等于，这也就是循环
 * 内直接使用else判断的原因。
 */
namespace AnsOne {
    // Thanks: armeria(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
    // Time: 0ms(100.00%)  Memory: 11.7MB(5.04%)
    class Solution {
    public:
        int findMin(std::vector<int> &nums) {
            int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] > nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return nums[l];
        }
    };
}

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
