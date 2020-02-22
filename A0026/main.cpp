// URL    : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
// Author : Modnar
// Date   : 2020/02/22

#include <set>
#include <vector>
#include <string>
#include <iostream>

/* ************************* */

/* ************************* */

/**
 * 使用STL中的set特性来解决
 *     set中的元素不会重复(此状态在inset时自动保持)，因此将nums中所有元素“丢到”
 * 一个set中，然后将set中所有元素放回nums中，返回set.size()即可。
 *     然而，这个算法没用到nums有序这一特性。
 */
namespace AnsOne {
    // Time: 44ms  Memory: 17MB
    class Solution {
    public:
        int removeDuplicates(std::vector<int> &nums) {
            std::set<int> iset;
            for (int val : nums)
                iset.insert(val);
            int i = 0;
            for (auto val : iset)
                nums[i++] = val;
            return iset.size();
        }
    };
}

/**
 * 使用iterator来去除nums中的重复元素
 *     这里需要注意的是vector的erase(iter)方法，会返回删除元素的下个元素的迭代器。
 */
namespace AnsTwo {
    // Time: 312ms  Memory: 15.4MB
    class Solution {
    public:
        int removeDuplicates(std::vector<int> &nums) {
            for (auto iter = nums.begin(); iter != nums.end(); ) {
                auto del_iter = iter + 1;
                while (del_iter != nums.end() && *del_iter == *iter)
                    del_iter = nums.erase(del_iter);
                iter = del_iter;
            }
            return nums.size();
        }
    };
}    

/**
 * 使用vector的assign高效拷贝来实现
 *     记录nums长度len。遍历nums，选择未重复的元素，放置到nums尾，注意不需要再遍历后
 * 加到尾端的元素。遍历结束后，将后加入的元素使用assign拷贝到nums上并返回此时的nums
 * 的size即可。
 */
namespace AnsThree {
    // Time: 16ms  Memory: 15.7MB
    class Solution {
    public:
        int removeDuplicates(std::vector<int> &nums) {
            auto len = nums.size();
            if (len == 0) return 0;
            int val = nums[0];
            nums.push_back(val);
            for (int i = 1; i != len; ++i)
                if (nums[i] != val) {
                    val = nums[i];
                    nums.push_back(val);
                }
            nums.assign(nums.begin()+len, nums.end());
            return nums.size();
        }
    };
}

/**
 * 双指针方法
 *     放置指针i、j=i+1，用j遍历nums，若nums[i] != nums[j]，则修改nums[i+1]的值为
 * nums[j]。用j遍历nums结束后，返回最后修改过的位置下标加一即可。
 */
namespace AnsFour {
    // Time: 8ms  Memory: 15.3MB
    class Solution {
    public:
        int removeDuplicates(std::vector<int> &nums) {
            std::vector<int>::size_type len = nums.size(), i = 0, j = 1;
            if (len <= 1) return len;
            while (j != len) {
                if (nums[i] != nums[j])
                    nums[++i] = nums[j];
                ++j;
            }
            return i+1;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsFour::Solution;
    std::vector<int> nums = {1, 1, 2};
    std::cout << (new Solution())->removeDuplicates(nums) << std::endl;
    // Ans: 2
    for (auto val : nums)
        std::cout << val << " ";
    // Ans: [1, 2]
    std::cout << std::endl;
    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << (new Solution())->removeDuplicates(nums) << std::endl;
    // Ans: 5
    for (auto val : nums)
        std::cout << val << " ";
    // Ans: [0, 1, 2, 3, 4]
    std::cout << std::endl;
    return 0;
}
