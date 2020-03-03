// URL    : https://leetcode-cn.com/problems/permutations/
// Author : Modnar
// Date   : 2020/02/29
// Thanks : liweiwei1419(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Thanks: liweiwei1419(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
// Time: 8ms(72.70%)  Memory: 10MB(17.43%)
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        int len = nums.size();
        std::vector<std::vector<int>> ans;
        if (len == 0) return ans;
        std::vector<bool> used(len);
        std::vector<int> path;
        dfs(nums, len, 0, path, used, ans);
        return ans;
    }

private:
    void dfs(const std::vector<int> &nums, int len, int depth, std::vector<int> &path,
            std::vector<bool> &used, std::vector<std::vector<int>> &ans) {
        if (depth == len) {
            ans.push_back(path);
            return ;
        }
        for (int i = 0; i != len; ++i) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(nums, len, depth+1, path, used, ans);
                used[i] = false;
                for (auto iter = path.begin(); iter != path.end(); )
                    if (*iter == nums[i]) {
                        iter = path.erase(iter);
                    } else {
                        ++iter;
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
