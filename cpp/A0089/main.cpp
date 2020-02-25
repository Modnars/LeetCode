// URL    : https://leetcode-cn.com/problems/gray-code/
// Author : Modnar
// Date   : 2020/02/24

#include <bits/stdc++.h>

/* ************************* */

// Thanks: 百度百科(https://baike.baidu.com/item/格雷码/6510858?fr=aladdin)
// Time: 4ms  Memory: 8.9MB
class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> ans{0};
        int len = 1 << n;
        for (int i = 1; i < len; ++i) {
            ans.push_back(i ^ (i>>1));
        }
        return ans;
    }
};

/* ************************* */

/**
 * val bits   idx   2    3     4    val  bits   idx     4
 *  1  0001  0000  00  000  0000  |   9  1001  1000  1100
 *  2  0010  0001  01  001  0001  |  10  1010  1001  1101
 *  3  0011  0010  11  011  0011  |  11  1011  1010  1111
 *  4  0100  0011  10  010  0010  |  12  1100  1011  1110
 *  5  0101  0100      110  0110  |  13  1101  1100  1010
 *  6  0110  0101      111  0111  |  14  1110  1101  1011
 *  7  0111  0110      101  0101  |  15  1111  1110  1001
 *  8  1000  0111      100  0100  |  16 10000  1111  1000
 */
int main(int argc, const char *argv[]) {
    for (int val : (new Solution())->grayCode(0))
        std::cout << val << " ";
    std::cout << std::endl;
    for (int val : (new Solution())->grayCode(2))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
