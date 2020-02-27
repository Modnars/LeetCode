// URL    : https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// Author : Modnar
// Date   : 2020/02/27
// Thanks : pinku-2

#include <bits/stdc++.h>

/* ************************* */

/**
 * 排序
 *     将数组排序，并直接选择第k大元素。
 */
// Complexity: O(n*logn)
// Time: 16ms(56.51%)  Memory: 12.5MB(5.11%)
class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

/* ************************* */

/**
 * 最小堆
 *     将数组中的所有元素放置到大小为k的最小堆中，如果向最小堆中添加的元素个数大于k，
 * 弹出堆顶元素。当所有元素遍历一遍后，最小堆保留着nums的最大的k个元素，而堆顶是这k
 * 个元素中最小的那个，也就是nums的第k大元素。
 */
namespace AnsOne {
    // Thanks: pinku-2
    // Complexity: O(nlogn)
    // Time: 8ms(97.95%)  Memory: 12.6MB(5.11%)
    class Solution {
    public:
        int findKthLargest(std::vector<int> &nums, int k) {
            int len = nums.size();
            if (!len || k > len) return 0;
            std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
            for (int i = 0; i != len; ++i) {
                heap.push(nums[i]);
                if (heap.size() == k+1)
                    heap.pop();
            }
            return heap.top();
        }
    };
}

namespace AnsTwo {
    // Thanks: pinku-2
    // Complexity: O(n)
    // Failed: WRONG_ANSWER
    class Solution {
    public:
        int findKthLargest(std::vector<int> &nums, int k) {
            int len = nums.size();
            if (!len || k > len) return 0;
            return select(nums, 0, len-1, len-k+1);
        }

    private:
        int select(std::vector<int> &nums, int left, int right, int target) {
            if (left == right) return nums[left];
            int cut = partition(nums, left, right), curr_rank = cut - left + 1;
            if (target == curr_rank)
                return nums[cut];
            else if (target < curr_rank)
                return select(nums, left, cut-1, curr_rank);
            else
                return select(nums, cut+1, right, target-curr_rank);
            return 0;
        }

        int partition(std::vector<int> &nums, int left, int right) {
            int cut = nums[right];
            int i = left;
            for (int j = left; j < right; ++j)
                if (nums[j] < cut) {
                    std::swap(nums[i], nums[j]);
                    ++i;
                }
            std::swap(nums[i], nums[right]);
            return i;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    std::cout << (new Solution())->findKthLargest(nums, 2) << std::endl;
    // Ans: 5
    return EXIT_SUCCESS;
}
