// URL    : https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
// Author : Modnar
// Date   : 2020/03/06
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Failed: WRONG_ANSWER
class Solution {
public:
    std::vector<std::vector<int>> findContinuousSequence(int target) {
        std::vector<std::vector<int>> ans;
        int beg = ((target / 2) & 1) ? (target / 2) : (target / 2 + 1);
        for (int i = beg; i >= 3; i -= 2) {
            if (target % i == 0) {
                std::vector<int> sum;
                int pos = target / i;
                for (int j = pos-i/2; j != pos-i/2+i; ++j)
                    sum.push_back(j);
                ans.push_back(sum);
            }
        }
        if (target & 1)
            ans.push_back({target/2, target/2+1});
        return ans;
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 4ms(84.07%)  Memory: 9.1MB(100.00%)
    class Solution {
    public:
        std::vector<std::vector<int>> findContinuousSequence(int target) {
            std::vector<std::vector<int>> vec;
            std::vector<int> res;
            for (int l = 1, r = 2; l < r; ) {
                int sum = (l + r) * (r - l + 1) / 2;
                if (sum == target) {
                    res.clear();
                    for (int i = l; i <= r; ++i) 
                        res.emplace_back(i);
                    vec.emplace_back(res);
                    l++;
                } else if (sum < target) {
                    r++;
                } else {
                    l++;
                }
            }
            return vec;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::cout << "3:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(3)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "4:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(4)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "5:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(5)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "6:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(6)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "7:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(7)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "9:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(9)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "10:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(10)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "15:\n";
    for (const auto &row : (new Solution())->findContinuousSequence(15)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
