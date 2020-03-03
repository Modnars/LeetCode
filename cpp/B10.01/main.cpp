// URL    : https://leetcode-cn.com/problems/sorted-merge-lcci/
// Author : Modnar
// Date   : 2020/03/03

#include <bits/stdc++.h>

/* ************************* */

// Time: 0ms(100.00%)  Memory: 11.6MB(100.00%)
class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i != -1 && j != -1) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (j != -1)
            nums1[k--] = nums2[j--];
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
