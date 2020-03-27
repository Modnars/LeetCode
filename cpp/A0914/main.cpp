// URL    : https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Author : Modnar
// Date   : 2020/03/27

#include <bits/stdc++.h>

/* ************************* */

/**
 *     首先使用数组进行存储每个数字出现的次数，再对这些次数求最大公因数。判断最大公因
 * 数是否为1即可。
 */
class Solution {
public:
    bool hasGroupsSizeX(std::vector<int> &deck) {
        std::vector<int> store(10000, 0);
        for (int i = 0; i != deck.size(); ++i)
            ++store[deck[i]];
        int max_factor = store[deck[0]];
        for (int i = 0; i != store.size(); ++i) {
            if (store[i]) {
                max_factor = gcd(max_factor, store[i]);
            }
        }
        return (max_factor != 1);
    }

private:
    int gcd(int a, int b) {
        int remain = a % b;
        while (remain) {
            a = b;
            b = remain;
            remain = a % b;
        }
        return b;
    }
};

/* ************************* */

/**
 * 使用map进行存储，记录每个数字出现的次数。key为该数字字面值，value为该数字出现次数。
 */
namespace AnsOne {
    // Time: 44ms(6.73%)  Memory: 17MB(5.71%)
    class Solution {
    public:
        bool hasGroupsSizeX(std::vector<int> &deck) {
            std::map<int, int> store;
            for (int i = 0; i != deck.size(); ++i)
                ++store[deck[i]];
            int max_factor = store[deck[0]];
            for (auto iter = store.begin(); iter != store.end(); ++iter) {
                max_factor = gcd(max_factor, iter->second);
            }
            return max_factor != 1;
        }

    private:
        int gcd(int a, int b) {
            int remain = a % b;
            while (remain) {
                a = b;
                b = remain;
                remain = a % b;
            }
            return b;
        }
    };
}

namespace AnsTwo {
    class Solution {
    public:
        bool hasGroupsSizeX(std::vector<int> &deck) {
            std::vector<int> store(10000, 0);
            for (auto v : deck)
                ++store[v];
            int g = -1;
            for (auto v : store)
                if (v) {
                    if (~g) g = gcd(g, v);
                    else g = v;
                }
            return g >= 2;
        }

    private:
        int gcd(int a, int b) {
            int remain = a % b;
            while (remain) {
                a = b;
                b = remain;
                remain = a % b;
            }
            return b;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::vector<int> nums = {1, 2, 3, 4, 4, 3, 2, 1};
    std::cout << (new Solution())->hasGroupsSizeX(nums) << std::endl;
    // Ans: 1 (true);
    nums = {1, 1, 1, 2, 2, 2, 3, 3};
    std::cout << (new Solution())->hasGroupsSizeX(nums) << std::endl;
    // Ans: 0 (false);
    nums = {1};
    std::cout << (new Solution())->hasGroupsSizeX(nums) << std::endl;
    // Ans: 0 (false);
    nums = {1, 1};
    std::cout << (new Solution())->hasGroupsSizeX(nums) << std::endl;
    // Ans: 1 (true);
    nums = {1, 1, 2, 2, 2, 2};
    std::cout << (new Solution())->hasGroupsSizeX(nums) << std::endl;
    // Ans: 1 (true);
    return EXIT_SUCCESS;
}
