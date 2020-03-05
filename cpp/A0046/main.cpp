// URL    : https://leetcode-cn.com/problems/permutations/
// Author : Modnar
// Date   : 2020/02/29
// Thanks : liweiwei1419(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: liweiwei1419(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
// Time: 4ms(93.44%)  Memory: 10.3MB(12.78%)
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<bool> used(nums.size());
        std::vector<int> path;
        backtrack(0, nums.size(), nums, used, path);
        return ans;
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

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3};
    for (const auto &row : (new Solution())->permute(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    nums = {1};
    for (const auto &row : (new Solution())->permute(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    nums = {0, 1};
    for (const auto &row : (new Solution())->permute(nums)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
