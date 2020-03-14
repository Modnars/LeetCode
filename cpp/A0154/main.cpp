// URL    : https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : Modnar
// Date   : 2020/03/14

#include <bits/stdc++.h>

/* ************************* */

// Time: 12ms(23.90%)  Memory: 13.5MB(5.08%)
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

namespace AnsOne {
    // Thanks: armeria(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
    // Time: 12ms(23.90%)  Memory: 13.6MB(5.08%)
    class Solution {
    public:
        int findMin(std::vector<int> &nums) {
            int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] > nums[r]) {
                    l = mid + 1;
                } else if (nums[mid] < nums[r]) {
                    r = mid;
                } else {
                    --r;
                }
            }
            return nums[l];
        }
    };
}

namespace AnsTwo {
    // Thanks: 嗯刷(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/c-tao-mo-neng-er-fen-mo-ban-4ms-by-pjpj/
    // Time: 4ms(98.00%)  Memory: 13.5MB(5.08%)
    class Solution {
    public:
        int findMin(std::vector<int> &nums) {
            int n = nums.size();
            while (n > 0 && nums[n-1] == nums[0]) {
                --n;
            }
            int l = -1, r = n, m;
            while (r - l > 1) {
                m = (r + l) / 2;
                if (nums[m] >= nums[0]) {
                    l = m;
                } else {
                    r = m;
                }
            }
            return r == n ? nums[0] : nums[r];
        }
    };
}

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<int> nums = {2, 2, 2, 0, 1};
    std::cout << solution->findMin(nums) << std::endl;
    // Ans: 0
    return EXIT_SUCCESS;
}
