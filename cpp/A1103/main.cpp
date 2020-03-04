// URL    : https://leetcode-cn.com/problems/distribute-candies-to-people/
// Author : Modnar
// Date   : 2020/03/05

#include <bits/stdc++.h>

/* ************************* */

// Time: 4ms(72.09%)  Memory: 8.8MB(5.23%)
class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        int count = 0;
        std::vector<int> ans(num_people, 0);
        while (candies) {
            ++count;
            ans[(count-1)%num_people] += (candies >= count ? count : candies);
            candies -= (candies >= count ? count : candies);
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    for (const auto &val : (new Solution())->distributeCandies(7, 4))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [1, 2, 3, 1]
    for (const auto &val : (new Solution())->distributeCandies(10, 3))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [5, 2, 3]
    return EXIT_SUCCESS;
}
