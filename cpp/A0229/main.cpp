// URL    : https://leetcode-cn.com/problems/majority-element-ii/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : onwaier(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Time: 20ms  Memory: 17.3MB
class Solution {
public:
    std::vector<int> majorityElement(std::vector<int> &nums) {
        std::map<int, int> times;
        std::set<int> ans;
        int len = nums.size();
        for (const int &val : nums) {
            if (times.find(val) == times.end()) {
                times[val] = 1;
            } else {
                times[val] += 1;
            }
            if (times[val] > len/3)
                ans.insert(val);
        }
        return std::vector<int>(ans.begin(), ans.end());
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {3, 2, 3};
    for (const int &val : (new Solution())->majorityElement(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [3]
    nums = {1, 1, 1, 3, 3, 2, 2, 2};
    for (const int &val : (new Solution())->majorityElement(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2]
    return EXIT_SUCCESS;
}
