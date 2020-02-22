// URL    : https://leetcode-cn.com/problems/palindrome-number/
// Author : Modnar
// Date   : 2020/02/21

#include <iostream>
#include <vector>
#include <cmath>

/* ************************* */

// Time: 28ms  Memory: 11.8MB
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        std::vector<int> data;
        while (x) {
            data.push_back(x%10);
            x /= 10;
        }
        auto iter1 = data.cbegin();
        auto iter2 = data.crbegin();
        for ( ; iter1 != data.cend(); ++iter1, ++iter2) {
            if (*iter1 != *iter2)
                return false;
        }
        return true;
    }
};

/* ************************* */

// Time: 68ms  Memory: 10.6MB
namespace AnsOne {
    // 使用时间来换空间
    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
                return false;
            int len;
            std::vector<int> data;
            for (len = 0; std::pow(10, len) <= x; ++len)
                ;
            for (int i = 0; i < len/2; ++i) {
                data.push_back(x%10);
                x /= 10;
            }
            if (len&1)
                x /= 10;
            for (auto iter = data.crbegin(); iter != data.crend(); ++iter, x /= 10)
                if (*iter != x%10)
                    return false;
            return true;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->isPalindrome(121) << std::endl;
    // Ans: 1
    std::cout << (new Solution())->isPalindrome(-121) << std::endl;
    // Ans: 0
    std::cout << (new Solution())->isPalindrome(10) << std::endl;
    // Ans: 0
    return 0;
}
