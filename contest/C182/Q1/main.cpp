// URL    : https://leetcode-cn.com/contest/weekly-contest-182/problems/find-lucky-integer-in-an-array/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/* ************************* */

// Time: 8ms(100.00%)  Memory: 10.6MB(100.00%)
class Solution {
public:
    int findLucky(std::vector<int> &arr) {
        std::vector<int> store(501);
        for (int i = 0; i != arr.size(); ++i)
            ++store[arr[i]];
        for (int i = 500; i != 0; --i)
            if (store[i] == i)
                return i;
        return -1;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> arr = {2, 2, 3, 4};
    std::cout << (new Solution())->findLucky(arr) << std::endl;
    // Ans: 2
    arr = {1, 2, 2, 3, 3, 3};
    std::cout << (new Solution())->findLucky(arr) << std::endl;
    // Ans: 3
    arr = {2, 2, 2, 3, 3};
    std::cout << (new Solution())->findLucky(arr) << std::endl;
    // Ans: -1
    arr = {5};
    std::cout << (new Solution())->findLucky(arr) << std::endl;
    // Ans: -1
    arr = {7, 7, 7, 7, 7, 7, 7};
    std::cout << (new Solution())->findLucky(arr) << std::endl;
    // Ans: 7
    return EXIT_SUCCESS;
}
