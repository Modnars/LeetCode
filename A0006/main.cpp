// URL    : https://leetcode-cn.com/problems/zigzag-conversion/
// Author : Modnar
// Date   : 2020/02/22
// Thanks : Official(@leetcode.cn)

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

/* ************************* */

/**
 * 通过拼接、反转字符串来获得最终结果
 *     对于样例：
 *   L   C   I   R
 *   E T O E S I I G
 *   E   D   H   N
 *     来说，第一列顺序，第二列逆序；若用一个string的vector来存储，则奇数列字符串
 * 顺序，偶数列字符串逆序，且偶数列长度最大长度为奇数列最大长度减2。于是考虑不断剪切
 * 字符串，对第偶数次剪切取其逆序串。为了保持字符串对其，不妨令偶数列的残缺部分用空格
 * 代替，从而便于后序拼接答案串。
 *
 *     分析可知，算法复杂度为O(2*n/([2*numRows-2]+1))。
 *
 */
// Time: 20ms  Memory: 12MB
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        int len = static_cast<int>(s.size()), limit = std::min(len, numRows), 
            lm = limit - 2, beg = 0;
        bool goingDown = true;
        std::vector<std::string> rows;
        while (beg < len) {
            if (goingDown) {
                rows.push_back(s.substr(beg, std::min(limit, len-beg)));
                beg += std::min(limit, len-beg);
            } else {
                std::string l = s.substr(beg, std::min(lm,len-beg));
                l = " " + l + std::string(limit-static_cast<int>(l.size())-1, ' ');
                rows.push_back(reverse(l));
                beg += std::min(lm, len-beg);
            }
            goingDown = !goingDown;
        }
        for (auto s : rows)
            std::cout << s << "\t" << s.size() << std::endl;
        std::string ans = "";
        for (int j = 0; j != limit; ++j)
            for (int i = 0; i != rows.size(); ++i) {
                if (j >= rows[i].size()) {
                    break;
                }
                if (rows[i][j] == ' ')
                    continue;
                ans += rows[i][j];
            }
        return ans;
    }

private:
    std::string reverse(std::string s) {
        if (s == "")
            return "";
        std::string::size_type i = 0, j = s.size()-1;
        while (i < j)
            std::swap(s[i++], s[j--]);
        return s;
    }
};

/* ************************* */

// Thanks: Official(@leetcode.cn)
// Time: 4ms  Memory: 12.9MB
namespace AnsOne {
    class Solution {
    public:
        std::string convert(std::string s, int numRows) {
            if (numRows == 1)
                return s;
            int currentRow = 0, limit = std::min(static_cast<int>(s.size()), numRows);
            std::vector<std::string> rows(limit);
            bool goingDown = false;
            for (char ch : s) {
                rows[currentRow] += ch;
                if (currentRow == limit-1 || currentRow == 0)
                    goingDown = !goingDown;
                currentRow += goingDown ? 1 : -1;
            }
            std::string ans = "";
            for (std::string s : rows)
                ans += s;
            return ans;
        }
    };
}

// Time: 24ms  Memory: 13.5MB
namespace AnsTwo {
    /**
     * 通过拼接、反转字符串来获得最终结果
     *     对于样例：
     *   L   C   I   R
     *   E T O E S I I G
     *   E   D   H   N
     *     来说，第一列顺序，第二列逆序；若用一个string的vector来存储，则奇数列字符串
     * 顺序，偶数列字符串逆序，且偶数列长度最大长度为奇数列最大长度减2。于是考虑不断
     * 剪切字符串，对第偶数次剪切取其逆序串。为了保持字符串对其，不妨令偶数列的残缺
     * 部分用空格代替，从而便于后序拼接答案串。
     *     这是对默认解的优化，然而优化结果不尽人意。
     *
     *     分析可知，算法复杂度为O(2*n/([2*numRows-2]+1))。
     */
    class Solution {
    public:
        std::string convert(std::string s, int numRows) {
            if (numRows == 1) return s;
            int len = static_cast<int>(s.size()), limit = std::min(len, numRows), 
                lm = limit - 2, beg = 0;
            bool goingDown = true;
            std::vector<std::string> rows(limit);
            while (beg < len) {
                int i = 0;
                if (goingDown) {
                    for (char ch : s.substr(beg, std::min(limit, len-beg)))
                        rows[i++] += ch;
                    beg += std::min(limit, len-beg);
                } else {
                    std::string l = s.substr(beg, std::min(lm,len-beg));
                    l = " " + l + std::string(limit-l.size()-1, ' ');
                    for (char ch : reverse(l))
                        rows[i++] += ch;
                    beg += std::min(lm, len-beg);
                }
                goingDown = !goingDown;
            }
            std::string ans = "";
            for (std::string s : rows) {
                for (auto iter = s.begin(); iter != s.end(); ++iter)
                    if (*iter == ' ') {
                        s.erase(iter);
                        --iter;
                    }
                ans += s;
            }
            return ans;
        }

    private:
        std::string reverse(std::string s) {
            if (s == "")
                return "";
            std::string::size_type i = 0, j = s.size()-1;
            while (i < j)
                std::swap(s[i++], s[j--]);
            return s;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::cout << (new Solution())->convert("LEETCODEISHIRING", 2) << std::endl;
    // Ans: "LECDIHRNETOESIIG"
    std::cout << (new Solution())->convert("LEETCODEISHIRING", 3) << std::endl;
    // Ans: "LCIRETOESIIGEDHN"
    std::cout << (new Solution())->convert("LEETCODEISHIRING", 4) << std::endl;
    // Ans: "LDREOEIIECIHNTSG"
    std::cout << (new Solution())->convert("PAYPALISHIRING", 4) << std::endl;
    // Ans: "PINALSIGYAHRPI"
    std::cout << (new Solution())->convert("ABCDE", 4) << std::endl;
    // Ans: "ABCED"
    return 0;
}
