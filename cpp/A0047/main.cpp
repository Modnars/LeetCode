// URL    : https://leetcode-cn.com/problems/permutations-ii/
// Author : Modnar
// Date   : 2020/03/05
// Thanks : liweiwei1419(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Time: 140ms(12.43%)  Memory: 11.3MB(20.84%)
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<bool> used(nums.size());
        std::vector<int> path;
        backtrack(0, nums.size(), nums, used, path);
        return std::vector<std::vector<int>>(ans.begin(), ans.end());
    }

private:
    // std::vector<std::vector<int>> ans;
    std::set<std::vector<int>> ans;
    void backtrack(int curr, int lim, std::vector<int> &nums, 
            std::vector<bool> &used, std::vector<int> &path) {
        if (curr == lim) {
            // ans.push_back(path);
            ans.insert(path);
        } else {
            for (int i = 0; i != nums.size(); ++i) {
                if (!used[i]) {
                    path.push_back(nums[i]);
                    used[i] = true;
                    backtrack(curr+1, lim, nums, used, path);
                    used[i] = false;
                    path.pop_back();
                }
            }
        }
    }
};

/* ************************* */

/**
 * 回溯 + 剪枝
 *     对于重复的元素，进行剪枝。
 *     其剪枝策略是判断当前结点是否和同层遍历的前一结点值相同(因而需要有序)，若相同且
 * 前一结点未被使用(used[i-1] == false)，则将当前结点跳过(剪枝)。
 */
namespace AnsOne {
    // Thanks: liweiwei1419(@leetcode.cn)
    // Time: 8ms(89.32%)  Memory: 11.2MB(22.10%)
    class Solution {
    public:
        std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
            std::sort(nums.begin(), nums.end()); // 确保有序以便于后续剪枝
            std::vector<bool> used(nums.size());
            std::vector<int> path;
            backtrack(0, nums.size(), nums, used, path);
            return std::vector<std::vector<int>>(ans.begin(), ans.end());
        }

    private:
        std::vector<std::vector<int>> ans;
        void backtrack(int curr, int lim, std::vector<int> &nums, 
                std::vector<bool> &used, std::vector<int> &path) {
            if (curr == lim) {
                ans.push_back(path);
            } else {
                for (int i = 0; i != nums.size(); ++i) {
                    if (!used[i]) {
                        // 剪枝: 排除重复遍历的元素
                        if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                            continue;
                        path.push_back(nums[i]);
                        used[i] = true;
                        backtrack(curr+1, lim, nums, used, path);
                        used[i] = false;
                        path.pop_back();
                    }
                }
            }
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {1, 1, 2};
    for (const auto &row : (new Solution())->permuteUnique(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    nums = {3, 3, 0, 3};
    for (const auto &row : (new Solution())->permuteUnique(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
