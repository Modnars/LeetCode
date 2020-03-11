// URL    : https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
// Author : Modnar
// Date   : 2020/03/11
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 *     根据题目，三个部分的和相等，因此每部分的和均为sum/3，其中sum为整个数组的和。
 *     因此，从头遍历数组，每当一部分计算所得和值为sum/3，就开始计算下一段，由此得到
 * 是否存在满足题意的解。
 */
// Thanks: LeetCode(@leetcode.cn)
// Time: 84ms(18.60%)  Memory: 31.7MB(5.26%)
class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int> &A) {
        if (A.size() < 3) 
            return false;
        int sum = 0, i = 0, target = 0;
        for (i = 0; i != A.size(); ++i)
            sum += A[i];
        if (sum % 3) 
            return false;
        target = sum / 3, i = 0;
        for (sum = A[i++]; i < A.size(); ++i) {
            if (sum == target)
                break;
            sum += A[i];
        }
        if (i == A.size()) return false;
        for (sum = A[i++]; i < A.size(); ++i) {
            if (sum == target)
                break;
            sum += A[i];
        }
        if (i == A.size()) return false;
        for (sum = A[i++]; i < A.size(); ++i) {
            sum += A[i];
        }
        if (sum == target)
            return true;
        return false;
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/solution/1013-jiang-shu-zu-fen-cheng-he-xiang-deng-de-san-2/
    // Time: 40ms(99.49%)  Memory: 32.2MB(5.26%)
    class Solution {
    public:
        bool canThreePartsEqualSum(std::vector<int> &A) {
            int s = std::accumulate(A.begin(), A.end(), 0);
            if (s % 3 != 0) {
                return false;
            }
            int target = s / 3;
            int n = A.size(), i = 0, cur = 0;
            while (i < n) {
                cur += A[i];
                if (cur == target) {
                    break;
                }
                ++i;
            }
            if (cur != target) {
                return false;
            }
            int j = i + 1;
            while (j + 1 < n) {  // 需要满足最后一个数组非空
                cur += A[j];
                if (cur == target * 2) {
                    return true;
                }
                ++j;
            }
            return false;
        }
    };
}

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::vector<int> nums = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    std::cout << solution->canThreePartsEqualSum(nums) << std::endl;
    // Ans: 1 (true)
    nums = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    std::cout << solution->canThreePartsEqualSum(nums) << std::endl;
    // Ans: 0 (false)
    nums = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    std::cout << solution->canThreePartsEqualSum(nums) << std::endl;
    // Ans: 1 (true)
    nums = {1, -1, 1, -1};
    std::cout << solution->canThreePartsEqualSum(nums) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
