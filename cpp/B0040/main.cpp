// URL    : https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// Author : Modnar
// Date   : 2020/03/20
// Thanks : LeetCode(@leetcode.cn) Sweetiee 🍬(@leetcode.cn)

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

/**
 * 最大堆
 *     使用堆排序，使用一个最大堆保存k个数。当再加入的数值小于堆顶元素时，堆顶弹出、该
 * 元素入堆。遍历过arr之后，即可得到最小的k个数值。
 */
namespace AnsOne {
    // Complexity: Time: O(nlogk)  Space: O(k)
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 56ms(38.79%)  Memory: 21.7MB(100.00%)
    class Solution {
    public:
        std::vector<int> getLeastNumbers(std::vector<int> &arr, int k) {
            if (arr.size() < k) return arr;
            if (k == 0) return std::vector<int>();
            std::priority_queue<int> store;
            for (int i = 0; i != k; ++i)
                store.push(arr[i]);
            for (int i = k; i != arr.size(); ++i)
                if (arr[i] < store.top()) {
                    store.pop();
                    store.push(arr[i]);
                }
            std::vector<int> ans;
            for (int i = 0; i != k; ++i) {
                ans.emplace_back(store.top());
                store.pop();
            }
            return ans;
        }
    };
}

/**
 * 快排思想
 */
namespace AnsTwo {
    // Thanks: Sweetiee 🍬(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/3chong-jie-fa-miao-sha-topkkuai-pai-dui-er-cha-sou/
    // Time: 24ms(96.66%)  Memory: 21.5MB(100.00%)
    class Solution {
    public:
        std::vector<int> getLeastNumbers(std::vector<int> &arr, int k) {
            if (k == 0 || arr.size() == 0) return std::vector<int>();
            return quickSearch(arr, 0, arr.size()-1, k-1);
        }

    private:
        std::vector<int> quickSearch(std::vector<int> &nums, int lo, int hi, int k) {
            int j = partition(nums, lo, hi);
            if (j == k) {
                return std::vector<int> (nums.begin(), nums.begin()+j+1);
            }
            return j > k ? 
                quickSearch(nums, lo, j-1, k) : quickSearch(nums, j+1, hi, k);
        }

        int partition(std::vector<int> &nums, int lo, int hi) {
            int key = nums[lo];
            int i = lo, j = hi + 1;
            while (true) {
                while (++i <= hi && nums[i] < key) ;
                while (--j >= lo && nums[j] > key) ;
                if (i >= j) break;
                std::swap(nums[i], nums[j]);
            }
            nums[lo] = nums[j];
            nums[j] = key;
            return j;
        }
    };
}

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
