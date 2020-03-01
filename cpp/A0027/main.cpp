// URL    : https://leetcode-cn.com/problems/remove-element/
// Author : Modnar
// Date   : 2020/03/01
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 双指针法
 *     首先，令i和j分别指向头元素和尾元素，令二者向中间移动。运行时，令i指向第一个待
 * 删除的元素，j指向尾端最后一个不为val的元素，若满足i<j，则将二者交换。一趟扫描结束，
 * 即可完成，最后返回j+1即可。
 */
// Time: 0ms(100.00%)  Memory: 11.2MB(5.30%)
class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            while (i != nums.size() && nums[i] != val)
                ++i;
            while (j != -1 && nums[j] == val)
                --j;
            if (i < j)
                std::swap(nums[i], nums[j]);
        }
        return j + 1;
    }
};

/* ************************* */

/**
 * 更优雅的双指针写法
 */
// Thanks: LeetCode(@leetcode.cn)
// Time: 8ms(30.14%)  Memory: 11.2MB(5.30%)
namespace AnsOne {
    class Solution {
    public:
        int removeElement(std::vector<int> &nums, int val) {
            int i = 0, j = nums.size();
            while (i < j) {
                if (nums[i] == val) {
                    nums[i] = nums[j-1];
                    --j;
                } else {
                    ++i;
                }
            }
            return j;
        }
    };
}

/**
 * STL
 */
namespace AnsTwo {
    // Time: 4ms(80.60%)  Memory: 11.1MB(5.30%)
    class Solution {
    public:
        int removeElement(std::vector<int> &nums, int val) {
            for (auto iter = nums.begin(); iter != nums.end(); )
                if (*iter == val)
                    iter = nums.erase(iter);
                else
                    ++iter;
            return nums.size();
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::vector<int> nums = {3, 2, 2, 3};
    int ans = (new Solution())->removeElement(nums, 3);
    for (int i = 0; i != ans; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    ans = (new Solution())->removeElement(nums, 2);
    for (int i = 0; i != ans; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    nums = {1};
    ans = (new Solution())->removeElement(nums, 1);
    for (int i = 0; i != ans; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    nums = {3, 3};
    ans = (new Solution())->removeElement(nums, 3);
    for (int i = 0; i != ans; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
