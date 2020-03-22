// URL    : https://leetcode-cn.com/contest/weekly-contest-181/problems/create-target-array-in-the-given-order/
// Author : Modnar
// Date   : 2020/03/22

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    std::vector<int> createTargetArray(std::vector<int> &nums, std::vector<int> &index) {
        std::vector<int> ans;
        for (int i = 0; i != index.size(); ++i) {
            ans.insert(ans.begin()+index[i], nums[i]);
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<int> nums = {0, 1, 2, 3, 4}, index = {0, 1, 2, 2, 1};
    for (const auto &val : solution->createTargetArray(nums, index))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [0, 4, 1, 3, 2]
    nums = {1, 2, 3, 4, 0}, index = {0, 1, 2, 3, 0};
    for (const auto &val : solution->createTargetArray(nums, index))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [0, 4, 1, 3, 2]
    return EXIT_SUCCESS;
}
