// URL    : https://leetcode-cn.com/problems/single-number-iii/
// Author : Modnar
// Date   : 2020/02/25

#include <bits/stdc++.h>

/* ************************* */

/**
 * 位运算
 *     类似于“数组中每个元素均出现两次，仅一个元素出现一次，找出这个元素”，首先用check
 * 将所有元素异或一遍，得到的check定不为一(因为数组中两个元素不同)。此时就需要确定这
 * 两个元素之间的差异(此时的check实际上就是这两个不同元素的异或值)：check中某位值为1，
 * 就说明这两个不同元素在此位上不同。那么就按照此位将所有数据分为两组(一组与此位上的1
 * 与运算值为0，一组与此位上的1与运算值为1)，那么此时的两个不同元素就分别落到两个不同
 * 分组内，此时每个分组内结构一定是“数组中每个元素均出现两次，仅一个元素出现一次”，
 * 所以，问题“又回到最初的起点”，取出这两个数组中的那两个仅出现一次的数值，即可得解。
 */
// Time: 12ms(89.33%)  Memory: 12.2MB(5.64%)
class Solution {
public:
    std::vector<int> singleNumber(std::vector<int> &nums) {
        int check = 0;
        for (const int &val : nums)
            check ^= val;
        check = check & (-check);
        std::vector<int> ans(2);
        for (const int &val : nums)
            if (check & val)
                ans[0] ^= val;
            else
                ans[1] ^= val;
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> nums = {1, 2, 1, 3, 2, 5};
    for (const int &val : (new Solution())->singleNumber(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [3, 5]
    nums = {2, 1, 2, 3, 4, 1};
    for (const int &val : (new Solution())->singleNumber(nums))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [3, 4]
    return EXIT_SUCCESS;
}
