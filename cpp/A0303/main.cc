// URL    : https://leetcode-cn.com/problems/range-sum-query-immutable/
// Author : Modnar
// Date   : 2021/03/01

#include <bits/stdc++.h>

/* ************************* */

// Time: 120ms Memory: 16.6MB
class NumArray {
public:
    NumArray(std::vector<int> &nums) : nums_(nums) { }
    
    int sumRange(int i, int j) {
        return std::accumulate(nums_.begin() + i, nums_.begin() + j + 1, 0);
    }

private:
    std::vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

/* ************************* */

int main(int argc, char *const argv[]) {
    return EXIT_SUCCESS;
}

