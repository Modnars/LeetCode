// URL    : https://leetcode-cn.com/problems/product-of-array-except-self/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 左右乘积列表
 *     通过构建左右乘积列表(productL和productR)来存储位置i左侧/右侧所有数值的乘积，
 * 很自然地，productL[i] = productL[i-1] * num[i-1] (productR类似)。于是在得到
 * 位置i的左右两侧乘积列表之后，ans[i] = productL[i] * productR[i]，遍历一遍即可求解。
 */
// Thanks: LeetCode(@leetcode.cn)
// Complexity: Time: O(n)  Space: O(n)
// Time: 24ms(55.82%)  Memory: 18.2MB(5.08%)
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        std::vector<int> ans(nums.size());
        if (nums.size() == 0) return ans;
        std::vector<int> productL(nums.size(), 1), productR(nums.size(), 1);
        for (int i = 1; i != nums.size(); ++i)
            productL[i] = nums[i-1] * productL[i-1];
        for (int j = nums.size()-2; j != -1; --j)
            productR[j] = nums[j+1] * productR[j+1];
        for (int i = 0; i != nums.size(); ++i)
            ans[i] = productL[i] * productR[i];
        return ans;
    }
};

/* ************************* */

/**
 * 进阶优化
 *     思路同构建左右双侧乘积列表相同，这里可以直接用ans作为左侧乘积列表，同时对于右侧
 * 乘积列表来说，可以使用临时变量R来缓存当前位置的右侧乘积，此时只需要再从右向左遍历
 * 一遍即可。由此可知，此算法不仅优化了程序存储空间(避免了productR的空间)，同时减少了
 * 一趟遍历，即同时优化了时间性能。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: Time: O(n)  Space: O(1)
    // Time: 20ms(63.52%)  Memory: 17.8MB(5.08%)
    class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int> &nums) {
            std::vector<int> ans(nums.size());
            if (!nums.size()) return ans;
            ans[0] = 1;
            for (int i = 1; i != nums.size(); ++i)
                ans[i] = nums[i-1] * ans[i-1];
            int R = 1;
            for (int j = nums.size()-2; j != -1; --j) {
                R = R * nums[j+1];
                ans[j] = ans[j] * R;
            }
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {1, 2, 3, 4};
    for (const int &val : (new Solution())->productExceptSelf(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [24, 12, 8, 6]
    return EXIT_SUCCESS;
}
