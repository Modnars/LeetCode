// URL    : https://leetcode-cn.com/problems/sort-an-array/
// Author : Modnar
// Date   : 2020/03/31

#include <bits/stdc++.h>

/* ************************* */

/**
 * STL
 */
// Time: 56ms(32.33%)  Memory: 15.8MB(21.09%)
class Solution {
public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

/* ************************* */

/**
 * 快排
 */
namespace AnsOne {
    // Time: 48ms(40.04%)  Memory: 15.9MB(21.09%)
    // Thanks: Baidu
    class Solution {
    public:
        std::vector<int> sortArray(std::vector<int> &nums) {
            quicksort(nums, 0, nums.size()-1);
            return nums;
        }

    private:
        void quicksort(std::vector<int> &nums, int m, int n) {
            if (m < n) {
                int l = m, r = n+1, k = l + ((r - l) >> 1), key = nums[k];
                std::swap(nums[m], nums[k]);
                while (l < r) {
                    while (nums[++l] < key) { if (l == n) break; }
                    while (nums[--r] > key) { if (r == m) break; }
                    if (l < r) std::swap(nums[l], nums[r]);
                }
                std::swap(nums[m], nums[r]);
                quicksort(nums, m, r-1);
                quicksort(nums, r+1, n);
            }
        }
    };
}

int main(int argc, const char *argv[]) {
    auto solution = std::make_shared<AnsOne::Solution>();
    std::vector<int> nums = {5, 2, 3, 1};
    for (const auto &val : solution->sortArray(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3, 5]
    nums = {5, 1, 1, 2, 0, 0};
    for (const auto &val : solution->sortArray(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [0, 0, 1, 1, 2, 5]
    nums = {};
    for (const auto &val : solution->sortArray(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [0, 0, 1, 1, 2, 5]
    return EXIT_SUCCESS;
}
