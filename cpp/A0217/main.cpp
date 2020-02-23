// URL    : https://leetcode-cn.com/problems/contains-duplicate/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

/* ************************* */

// Complexity: Time: O(n) Space: O(n)
// Time: 84ms  Memory: 22.5MB
class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::set<int> check;
        for (int &i : nums)
           if (check.find(i) == check.end())
              check.insert(i);
           else
              return true;
        return false;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << (new Solution())->containsDuplicate(nums) << std::endl;
    // 1 (true)
    nums = {1, 2, 3, 4};
    std::cout << (new Solution())->containsDuplicate(nums) << std::endl;
    // 0 (false)
    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << (new Solution())->containsDuplicate(nums) << std::endl;
    // 1 (true)
    return EXIT_SUCCESS;
}
