// URL    : https://leetcode-cn.com/contest/weekly-contest-181/problems/four-divisors/
// Author : Modnar
// Date   : 2020/03/22

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    int sumFourDivisors(std::vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i != nums.size(); ++i)
            ans += sumFourFactors(nums[i]);
        return ans;
    }

private:
    int sumFourFactors(int val) {
        int count = 0, ans = 0;
        for (int i = 2; i <= val/2; ++i) {
            if (val % i == 0) {
                ++count;
                ans += i;
            }
            if (count > 2) break;
        }
        ans += 1 + val;
        return (count == 2) ? ans : 0;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {21, 4, 7};
    std::cout << (new Solution())->sumFourDivisors(nums) << std::endl;
    // Ans: 32
    return EXIT_SUCCESS;
}
