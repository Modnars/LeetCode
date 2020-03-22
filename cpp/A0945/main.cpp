// URL    : https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
// Author : Modnar
// Date   : 2020/03/22

#include <bits/stdc++.h>

/* ************************* */

/**
 * 贪心算法
 *     将数组排序，对排序后的数组进行修改，使得新的数组内不存在重复值。此时每一步操作
 * 都只需要添加最小的修改使得该条件成立，因而遍历一遍以后，将满足整个数组内不存在重复
 * 值且所移动的次数最少。
 */
// Time: 80ms(64.91%)  Memory: 25.9MB(20.83%)
class Solution {
public:
    int minIncrementForUnique(std::vector<int> &A) {
        if (A.size() == 0) return 0;
        std::sort(A.begin(), A.end()); // 对数组进行排序
        int ans = 0; // 记录最小移动次数
        for (int i = 0; i != A.size()-1; ++i)
            if (A[i] >= A[i+1]) {           // 若当前值较下一个相邻元素大
                ans += A[i] - A[i+1] + 1;   // ans增加最小修改次数
                A[i+1] = A[i] + 1;          // 修改下一个相邻元素
            }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<int> nums = {1, 2, 2};
    std::cout << solution->minIncrementForUnique(nums) << std::endl;
    // Ans: 1
    nums = {3, 2, 1, 2, 1, 7};
    std::cout << solution->minIncrementForUnique(nums) << std::endl;
    // Ans: 6
    return EXIT_SUCCESS;
}
