// URL    : https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// Author : Modnar
// Date   : 2020/03/20

#include <bits/stdc++.h>

/* ************************* */

// Complexity: Time: O(nlogn)  Space: O(1)
// Time: 36ms(79.21%)  Memory: 20.6MB(100.00%)
class Solution {
public:
    std::vector<int> getLeastNumbers(std::vector<int> &arr, int k) {
        std::sort(arr.begin(), arr.end());
        return std::vector<int>(arr.begin(), arr.begin()+k);
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
