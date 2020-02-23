// URL    : https://leetcode-cn.com/problems/integer-to-roman/
// Author : Modnar
// Date   : 2020/02/23
// Thanks : int myheart(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

// Time: 8ms  Memory: 8.4MB
class Solution {
public:
    std::string intToRoman(int num) {
        std::string ans = "";
        while (num >= 1000) {
            ans += Str(1000);
            num -= 1000;
        }
        if (num >= 900) {
            ans += Str(900);
            num -= 900;
        } else if (num >= 500) {
            ans += Str(500);
            num -= 500;
        } else if (num >= 400) {
            ans += Str(400);
            num -= 400;
        }
        while (num >= 100) {
            ans += Str(100);
            num -= 100;
        }
        if (num >= 90) {
            ans += Str(90);
            num -= 90;
        } else if (num >= 50) {
            ans += Str(50);
            num -= 50;
        } else if (num >= 40) {
            ans += Str(40);
            num -= 40;
        }
        while (num >= 10) {
            ans += Str(10);
            num -= 10;
        }
        if (num == 9) {
            ans += Str(9);
            num -= 9;
        } else if (num >= 5) {
            ans += Str(5);
            num -= 5;
        } else if (num == 4) {
            ans += Str(4);
            num -= 4;
        }
        while (num > 0) {
            ans += Str(1);
            num -= 1;
        }
        return ans;
    }

private:
    std::string Str(int val) {
        switch (val) {
            case 1:     return "I";
            case 5:     return "V";
            case 10:    return "X";
            case 50:    return "L";
            case 100:   return "C";
            case 500:   return "D";
            case 1000:  return "M";
            case 4:     return "IV";
            case 9:     return "IX";
            case 40:    return "XL";
            case 90:    return "XC";
            case 400:   return "CD";
            case 900:   return "CM";
            default:    return "";
        }
        return "";
    }
};

/* ************************* */

namespace AnsOne {
    // Thanks : int myheart(@leetcode.cn)
    // Time: 52ms  Memory: 21.4MB
    class Solution {
    public:
        std::string intToRoman(int num) {
            std::vector<std::vector<std::string>> c = {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
                {"", "M", "MM", "MMM"}};
            std::string roman;
            roman.append(c[3][num / 1000]);
            roman.append(c[2][num / 100 % 10]);
            roman.append(c[1][num / 10 % 10]);
            roman.append(c[0][num % 10]);
            return roman;
        }
    };
}

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->intToRoman(3) << std::endl;
    // Ans: III
    std::cout << (new Solution())->intToRoman(4) << std::endl;
    // Ans: IV
    std::cout << (new Solution())->intToRoman(9) << std::endl;
    // Ans: IX
    std::cout << (new Solution())->intToRoman(58) << std::endl;
    // Ans: LVIII
    std::cout << (new Solution())->intToRoman(1994) << std::endl;
    // Ans: MCMXCIV
    return EXIT_SUCCESS;
}
