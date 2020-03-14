// URL    : https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
// Author : Modnar
// Date   : 2020/03/14

#include <bits/stdc++.h>

/* ************************* */

// Time: 8ms(73.85%)  Memory: 13.6MB(100.00%)
class Solution {
public:
    int minArray(std::vector<int> &numbers) {
        if (numbers.size() == 0) return 0;
        int min_val = numbers[0];
        for (int i = 1; i != numbers.size(); ++i)
            if (numbers[i] < min_val) {
                min_val = numbers[i];
                break;
            }
        return min_val;
    }
};

/* ************************* */

namespace AnsTwo {
    // Thanks: 嗯刷(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/c-tao-mo-neng-er-fen-mo-ban-4ms-by-pjpj/
    // Time: 8ms(73.64%)  Memory: 13.6MB(100.00%)
    class Solution {
    public:
        int minArray(std::vector<int> &nums) {
            int n = nums.size();
            while (n > 0 && nums[n-1] == nums[0]) {
                --n;
            }
            int l = -1, r = n, m;
            while (r - l > 1) {
                m = (r + l) / 2;
                if (nums[m] >= nums[0]) {
                    l = m;
                } else {
                    r = m;
                }
            }
            return r == n ? nums[0] : nums[r];
        }
    };
}

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
