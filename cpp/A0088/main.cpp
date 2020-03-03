// URL    : https://leetcode-cn.com/problems/merge-sorted-array/
// Author : Modnar
// Date   : 2020/02/22
// Thanks : LeetCode(@leetcode.cn)

#include <vector>
#include <cstdlib>
#include <iostream>

/* ************************* */

/**
 * 拷贝 + 归并 (双指针/从前向后)
 *     将nums1的前m个值拷贝到cp_nums1，然后将cp_nums1和nums2归并至nums1即可。
 */
// Time: 8ms  Memory: 11.6MB
class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        std::vector<int> cp_nums1(nums1.begin(), nums1.begin()+m);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (cp_nums1[i] < nums2[j])
                nums1[k++] = cp_nums1[i++];
            else
                nums1[k++] = nums2[j++];
        }
        while (i < m)
            nums1[k++] = cp_nums1[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
};


/**
 * 双指针/从后向前
 *     将i、j分别置于nums1[m-1]和nums2[n-1]的位置。从后向前遍历，若nums1[i]>nums2[j]，
 * 则将nums1[i]置于nums1[k]的位置(k为已确定部分的最后位置)；否则，将nums2[j]置于该位置
 * 由于这个过程对于nums1来说不过是将其上的某个位置的元素移动到其上的另一个位置，因此
 * 可以确定，当nums2遍历结束时，即可确定整个过程结束。
 *     需要注意的是，可能m为0，也就是原nums1上的空间均是为nums2准备的，此时就要考虑到
 * 将nums2的全部元素拷贝至nums1上。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 4ms  Memory: 11.4MB
    class Solution {
    public:
        void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
            int i = m - 1, j = n - 1, k = m + n - 1;
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
}

/* ************************* */

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    (new Solution())->merge(nums1, 3, nums2, 3);
    for (int val : nums1)
        std::cout << val << " ";
    // Ans: 1, 2, 2, 3, 5, 6
    std::cout << std::endl;
    nums1 = {0}, nums2 = {1};
    (new Solution())->merge(nums1, 0, nums2, 1);
    for (int val : nums1)
        std::cout << val << " ";
    // Ans: 1
    std::cout << std::endl;
    nums1 = {2, 0}, nums2 = {1};
    (new Solution())->merge(nums1, 1, nums2, 1);
    for (int val : nums1)
        std::cout << val << " ";
    // Ans: 1, 2
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
