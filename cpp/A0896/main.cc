// URL    : https://leetcode-cn.com/problems/monotonic-array/
// Author : Modnar
// Date   : 2021/02/28

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    bool isMonotonic(std::vector<int> &A) {
        if (A.size() <= 1) {
            return true;
        }
        int idx = 0;
        // 此时无法分辨单调性
        while (idx + 1 < A.size() && A[idx] == A[idx+1]) {
            ++idx;
        }
        if (idx >= A.size() - 1) {
            return true;
        }
        // 可区分单调性
        // 第1种写法: Time: 76ms Memory: 48.2MB
        if (A[idx] < A[idx+1]) {
            for (int i = idx; i < A.size() - 1; ++i) {
                if (A[i] > A[i+1]) {
                    return false;
                }
            }
        } else {
            for (int i = idx; i < A.size() - 1; ++i) {
                if (A[i] < A[i+1]) {
                    return false;
                }
            }
        }
        // 第2种写法: Time: 92ms Memory: 48.2MB
        // for (int i = idx; i < A.size() - 1; ++i) {
        //     if (A[idx] < A[idx+1] && A[i] > A[i+1]) {
        //         return false;
        //     }
        //     if (A[idx] > A[idx+1] && A[i] < A[i+1]) {
        //         return false;
        //     }
        // }
        return true;
    }
};

/* ************************* */

int main(int argc, char *const argv[]) {
    std::vector<int> A = {1, 2, 2, 3};
    std::cout << ((new Solution())->isMonotonic(A) ? "True" : "Fasle") << std::endl;
    // True
    A = {6, 5, 4, 4};
    std::cout << ((new Solution())->isMonotonic(A) ? "True" : "Fasle") << std::endl;
    // True
    A = {1, 3, 2};
    std::cout << ((new Solution())->isMonotonic(A) ? "True" : "Fasle") << std::endl;
    // False
    A = {1, 2, 4, 5};
    std::cout << ((new Solution())->isMonotonic(A) ? "True" : "Fasle") << std::endl;
    // True
    A = {1, 1, 1};
    std::cout << ((new Solution())->isMonotonic(A) ? "True" : "Fasle") << std::endl;
    // True
    return EXIT_SUCCESS;
}

