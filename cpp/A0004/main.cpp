// URL    : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
// Author : Modnar
// Date   : 2020/02/21
// Thanks : windliang(@leetcode.cn)

#include <iostream>
#include <vector>

/* ************************* */

// Time: 44ms  Memory: 91.1MB
// Complexity: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        auto len1 = nums1.size(), len2 = nums2.size(), len = len1 + len2;
        int i = 0, j = 0, k = 0, limit = len / 2;
        std::vector<int> cache(limit+1); 
        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j])
                cache[k++] = nums1[i++];
            else
                cache[k++] = nums2[j++];
            if (k == limit+1)
                break;
        }
        while (i < len1 && k != limit+1)
            cache[k++] = nums1[i++];
        while (j < len2 && k != limit+1)
            cache[k++] = nums2[j++];
        return (len & 1) ? cache[limit] : (cache[limit-1]+cache[limit])/2.0;
    }
};

/* ************************* */

namespace AnsOne {

    using std::vector;

    // Time: 36ms  Memory: 91.8MB
    // Complexity: O(m+n)
    class Solution {
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
            // 也可针对nums1、nums2为空的特殊情况进行简单优化
            std::vector<int> ans = merge(nums1, nums2);
            auto len = ans.size();
            return (len%2 == 0) ? (ans[len/2-1]+ans[len/2])/2.0 : ans[len/2];
        }

    private:
        std::vector<int> merge(std::vector<int> &nums1, std::vector<int> &nums2) {
            std::vector<int> resVec;
            int i = 0, j = 0;
            int len1 = nums1.size(), len2 = nums2.size();
            while (i != len1 && j != len2) {
                if (nums1[i] < nums2[j])
                    resVec.push_back(nums1[i++]);
                else
                    resVec.push_back(nums2[j++]);
            }
            while (i != len1)
                resVec.push_back(nums1[i++]);
            while (j != len2)
                resVec.push_back(nums2[j++]);
            return resVec;
        }
    };
}

int main(int argc, const char *argv[]) {
    // using Solution = AnsOne::Solution;
    std::vector<int> nums1 = {1, 3}, nums2 = {2};
    std::cout << (new Solution())->findMedianSortedArrays(nums1, nums2) << std::endl;
    nums1 = {1, 2}, nums2 = {3, 4};
    std::cout << (new Solution())->findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
