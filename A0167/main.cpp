// URL    : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
// Author : Modnar
// Date   : 2020/02/20

#include <map>
#include <vector>
#include <cstdlib>
#include <iostream>

/* ************************* */

// 使用同A0001相同的算法
// Time: 8ms  Memory: 9.9MB
class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::map<int, int> mpos;
        for (int i = 0; i != nums.size(); ++i) {
            if (mpos.find(nums[i]) == mpos.end())
                mpos[target-nums[i]] = i + 1;
            else
                return std::vector<int>({mpos[nums[i]], i+1});
        }
        return std::vector<int>();
    }
};

/* ************************* */

// Time: 8ms  Memory: 9.7MB
namespace AnsOne {
    /**
     * 使用双下标来访问vector两端，当两下标所指值之和小于target时，低下标增加；大于
     * 时，高下标减小，直至高低下标交换位置(按题意，此情况不会发生)。
     */
    class Solution {
    public:
        std::vector<int> twoSum(std::vector<int> &nums, int target) {
            for (int i = 0, j = nums.size()-1; i < j; ) {
                int sum = nums[i] + nums[j];
                if (sum < target)
                    ++i;
                else if (sum > target)
                    --j;
                else
                    return std::vector<int>({i+1, j+1});
            }
            return std::vector<int>();
        }
    };
}

// Time: 8ms  Memory: 9.8MB
namespace AnsTwo {
    /**
     * 对vector从头遍历，针对当前下标，对其右侧所有元素(按从左到右即从小到大顺序)进行
     * 二分查找，直到某个下标满足题意。
     */
    class Solution {
    public:
        std::vector<int> twoSum(std::vector<int> &nums, int target) {
            int length = nums.size();
            for (int i = 0; i != length; ++i) {
                int pos;
                if ((pos = binSearch(nums, i+1, length, target-nums[i])) != -1)
                    return std::vector<int>({i+1, pos+1});
            }
            return std::vector<int>();
        }

    private:
        int binSearch(const std::vector<int> &nums, int low, int high, int target) {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (target > nums[mid])
                    low = mid + 1;
                else if (target < nums[mid])
                    high = mid - 1;
                else
                    return mid;
            }
            return -1;
        }
    };
}

int main(int argc, char *argv[]) {
    std::vector<int> nums = {5, 25, 75};
    for (int &val : (new AnsTwo::Solution())->twoSum(nums, 100))
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}
