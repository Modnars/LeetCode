// URL    : https://leetcode-cn.com/problems/majority-element/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * 哈希散列
 *     将所有元素放入map中(key为元素值，value为元素出现次数)，当某个元素出现次数多于
 * nums总元素数一半时，就足以判断这个元素为众数。
 */
// Time: 28ms  Memory: 21.3MB
class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        std::map<int, int> times;
        int len = nums.size();
        for (auto val: nums) {
            if (times.find(val) == times.end()) {
                times[val] = 1;
            } else {
                times[val] += 1;
            }
            if (times[val] == (len+1)/2) // 如果某个数值出现的次数超过nums总数的一半，
                return val;              // 则返回这个数值(这里用到了整数除法取整)
        }
        return -1; // 无满足条件的值，返回-1
    }
};

/* ************************* */

/**
 * Boyer-Moore算法
 *     通过投票选举，维护一个winner。当winner的获票数为零时，更新winner为下一个
 * 待选者；否则，当当前获票不是投给winner的票时，winner获票数减一；当当前获票是投给
 * winner的票时，winner获票数加一。
 *     针对本题来说，遍历一遍结束后，直接返回winner即可。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 20ms  Memory: 21.1MB
    class Solution {
    public:
        int majorityElement(std::vector<int> &nums) {
            int cand = 0, k = 0;
            for (const int &val : nums)
                if (!k) {
                    cand = val;
                    ++k;
                } else if (cand == val) {
                    ++k;
                } else {
                    --k;
                }
            return cand;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> nums = {3, 2, 3};
    std::cout << (new Solution())->majorityElement(nums) << std::endl;
    // Ans: 3
    nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << (new Solution())->majorityElement(nums) << std::endl;
    // Ans: 2
    nums = {1};
    std::cout << (new Solution())->majorityElement(nums) << std::endl;
    // Ans: 1
    return EXIT_SUCCESS;
}
