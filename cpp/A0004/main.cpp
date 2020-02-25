// URL    : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
// Author : Modnar
// Date   : 2020/02/21
// Thanks : windliang(@leetcode.cn), Mia(@leetcode.cn)

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

namespace AnsTwo {
    using std::vector;

    // Thanks: Mia
    // Complexity: O(log(min(m, n)))
    // Time: 32ms  Memory: 91MB
    class Solution {
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
            int n = nums1.size();
            int m = nums2.size();
            if (n > m) { // 保证数组1一定最短
                return findMedianSortedArrays(nums2, nums1);
            }
            // Ci 为第i个数组的割，比如C1为2时表示第1个数组只有2个元素。
            // LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
            int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  
            // 我们目前是虚拟加了'#'所以数组1是2*n长度
            while (lo <= hi) {      // 二分
                c1 = (lo + hi) / 2; // c1是二分的结果
                c2 = m + n - c1;
                LMax1 = (c1 == 0)     ? INT_MIN : nums1[(c1 - 1) / 2];
                RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
                LMax2 = (c2 == 0)     ? INT_MIN : nums2[(c2 - 1) / 2];
                RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];
                if (LMax1 > RMin2)
                    hi = c1 - 1;
                else if (LMax2 > RMin1)
                    lo = c1 + 1;
                else
                    break;
            }
            return (std::max(LMax1, LMax2) + std::min(RMin1, RMin2)) / 2.0;
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
