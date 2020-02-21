// URL    : https://leetcode-cn.com/problems/two-sum/
// Author : Modnar
// Date   : 2020/02/20
// Thanks : Hao Chen(@github:haoel)

#include <map>
#include <vector>
#include <cstdlib>
#include <iostream>

/* ************************* */

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::map<int, int> mpos;
        for (int i = 0; i != nums.size(); ++i) {
            if (mpos.find(nums[i]) == mpos.end())
                mpos[target-nums[i]] = i;
            else
                return std::vector<int>({mpos[nums[i]], i});
        }
        return std::vector<int>();
    }
};

/* ************************* */

int main(int argc, char *argv[]) {
    std::vector<int> nums = {3, 2, 4};
    for (auto &val : (new Solution())->twoSum(nums, 6))
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}
