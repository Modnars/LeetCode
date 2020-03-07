// URL    : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author : Modnar
// Date   : 2020/03/06

#include <bits/stdc++.h>

/* ************************* */

/**
 * 二分查找 & 枚举遍历
 *     首先使用二分查找确定target的位置(可确定其所在的一个位置或判定其不存在)。若查到
 * target，则遍历找到其起点与终点，并返回；否则直接返回[-1, -1]即可。
 */
// Time: 8ms(87.73%)  Memory: 15.9MB(5.10%)
class Solution {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1, pos = -1;
        std::vector<int> ans;
        while (low <= high) {
            int mid = low + ((high - low) >> 2);
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                pos = mid;
                break;
            }
        }
        if (pos == -1) {
            return std::vector<int>({-1, -1});
        } else {
            int i;
            for (i = pos; i != -1; --i)
                if (nums[i] != target)
                    break;
            ans.emplace_back(i+1);
            for (i = pos; i != nums.size(); ++i)
                if (nums[i] != target)
                    break;
            ans.emplace_back(i-1);
        }
        return ans;
    }
};

/* ************************* */

/**
 * 二分搜索改进
 *     改进二分搜索，通过传入参数left(bool类型)来决定是否“在查询到target后，继续对左
 * 部分空间继续查询”以获得target起始坐标。若参数为false，则搜索右部分。
 *     针对搜索结果进行处理并返回即可。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 12ms(52.14%)  Memory: 15.8MB(5.10%)
    class Solution {
    public:
        std::vector<int> searchRange(std::vector<int> &nums, int target) {
            std::vector<int> ans({-1, -1}); // 初始化为“未查询到结果”状态
            int left = search_side_index(nums, target, true); // 获取target起始坐标
            if (left == nums.size() || nums[left] != target)  // 为查询到target
                return ans;
            ans[0] = left;
            ans[1] = search_side_index(nums, target, false) - 1; // 获取终止坐标
            return ans;
        }

    private:
        /**
         * 通过传入参数left来决定查询到target后继续遍历左或右部分
         * 若left为true，则返回target起始下标；否则返回target终止下标的下一位置下标
         */
        int search_side_index(const std::vector<int> &nums, int target, bool left) {
            int low = 0, high = nums.size(); // 注意high取值决定搜索区间开闭
            while (low < high) {
                int mid = low + ((high - low) >> 2);
                if (nums[mid] > target || (left && nums[mid] == target)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        };
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    for (const auto &val : (new Solution())->searchRange(nums, 8))
        std::cout << val << " ";
    std::cout << std::endl;
    for (const auto &val : (new Solution())->searchRange(nums, 6))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
