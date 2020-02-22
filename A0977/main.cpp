// URL    : https://leetcode-cn.com/problems/squares-of-a-sorted-array/
// Author : Modnar
// Date   : 2020/02/22

#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

/* ************************* */

// Time: 52ms  Memory: 27.3MB
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int> &A) {
        auto len = A.size();
        int i = 0, j = len-1, k = j;
        std::vector<int> ans(len);
        while (i <= j) {
            int a = A[i] * A[i], b = A[j] * A[j];
            if (a > b) {
                ans[k--] = a;
                ++i;
            } else {
                ans[k--] = b;
                --j;
            }
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> A = {-4, -1, 0, 3, 10};
    for (const int &val : (new Solution())->sortedSquares(A))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [0, 1, 9, 16, 100]
    A = {-7, -3, 2, 3, 11};
    for (const int &val : (new Solution())->sortedSquares(A))
        std::cout << val << " ";
    std::cout << std::endl;
    // Ans: [4, 9, 9, 49, 121]
    return EXIT_SUCCESS;
}
