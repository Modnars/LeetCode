// URL    : https://leetcode-cn.com/problems/subsets/
// Author : Modnar
// Date   : 2020/02/26

#include <bits/stdc++.h>

/* ************************* */

/**
 * 使用数字与存储位间的关系
 *     首先，ans.size()固定为2^nums.size()，所以这道题的复杂度必定很高。
 *     根据数学知识，ans.size()之所以等于2^nums.size()，是因为nums中的每个元素都有
 * “存在于子集”和“不存在于子集”两种状态，所以可以根据这个角度来判断nums中的每个元素
 * 是否存在于ans中。
 *     令len = ans.size()，那么对于0~len的每个数字来说(比如0~7)，其第i个位均可表示
 * nums[i]是否存在于ans中(比如对于ans[7]来说，7表示为111，就可以把nums中的三个数字
 * 均添加到ans[7]中，而对于ans[0]，0表示为000来说，恰恰相反，此时ans[0]就是空集)。
 * 理清了这一点，就可以很好地求解了。
 *     
 */
// Complexity: O(n*2^n)
// Time: 8ms(53.24%)  Memory: 9.5MB(27.53%)
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        int sz = nums.size(), len = (1 << sz);
        std::vector<std::vector<int>> ans(len);
        for (int i = 0; i != len; ++i)
            for (int j = 0; j != sz; ++j)
                if (i & (1<<j))
                    ans[i].push_back(nums[j]);
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3};
    int i = 0;
    for (auto vec : (new Solution())->subsets(nums)) {
        std::cout << ++i << ": ";
        for (auto val : vec)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
