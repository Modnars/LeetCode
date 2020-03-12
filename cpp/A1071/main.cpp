// URL    : https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/
// Author : Modnar
// Date   : 2020/03/12

#include <bits/stdc++.h>

/* ************************* */

/**
 * 使用GCD辅助计算
 *     对于s1和s2来说，其最大公因子串的长度和二者的长度依旧满足最大公因数的条件限制。
 * 因此，可以首先求二者长度的最大公因数，继而对每个串检查长度为该值的子串是否满足条
 * 件。若对于最大公因子的情况不满足，则要继续检查最大公因子的所有因子，对他们长度为
 * 该因子的子串进行检查，若满足，将子串返回，直到最终无结果，返回""为止。
 */
// Time: 8ms(62.28%)  Memory: 9.4MB(58.06%)
class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        int m = str1.size(), n = str2.size(), len = gcd(m, n); // 计算长度GCD
        // 如果有一个串为""，或者二者的首字符不同，则直接返回""
        if (m == 0 || n == 0 || str1[0] != str2[0])
            return "";
        // 对长度GCD的所有因子进行遍历
        for (int i = len; i != 0; --i) {
            // 非整除时表明该值不是GCD的因子
            if (len % i) continue;
            // 检查是否满足字符串整除条件
            if (check(str1, str1.substr(0, i)) && check(str2, str2.substr(0, i)))
                return str1.substr(0, i);
        }
        return "";
    }

private:
    // 求两整数最大公因子
    int gcd(int m, int n) {
        while (n) {
            int remain = m % n;
            m = n;
            n = remain;
        }
        return m;
    }

    // 判断factor是否为source的因子
    bool check(const std::string &source, const std::string &factor) {
        int sz = factor.size();
        for (int i = 0; i != source.size(); i += sz)
            if (source.substr(i, sz) != factor)
                return false;
        return true;
    }
};

/* ************************* */

/**
 * 如果str1和str2存在最大公因子，那么一定有str1+str2 = str2+str1。详情请参阅题解。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Solution: https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/zi-fu-chuan-de-zui-da-gong-yin-zi-by-leetcode-solu/
    // Time: 0ms(100.00%)  Memory: 8.3MB(100.00%)
    class Solution {
    public:
        std::string gcdOfStrings(std::string str1, std::string str2) {
            if (str1+str2 != str2+str1) return "";
            return str1.substr(0, gcd(static_cast<int>(str1.size()), 
                        static_cast<int>(str2.size())));
        }

    private:
        int gcd(int m, int n) {
            while (n) {
                int remain = m % n;
                m = n;
                n = remain;
            }
            return m;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    Solution *solution = new Solution();
    std::cout << solution->gcdOfStrings("ABCABC", "ABC") << std::endl;
    // Ans: "ABC"
    std::cout << solution->gcdOfStrings("ABABAB", "ABAB") << std::endl;
    // Ans: "AB"
    std::cout << solution->gcdOfStrings("LEET", "CODE") << std::endl;
    // Ans: ""
    std::cout << solution->gcdOfStrings("LEET", "") << std::endl;
    // Ans: ""
    return EXIT_SUCCESS;
}
