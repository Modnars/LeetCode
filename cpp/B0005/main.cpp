// URL    : https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
// Author : Modnar
// Date   : 2020/03/10

#include <bits/stdc++.h>

/* ************************* */

// Time: 0ms(100.00%)  Memory: 7.7MB(100.00%)
class Solution {
public:
    std::string replaceSpace(std::string s) {
        std::string::size_type pos;
        while ((pos = s.find(" ")) != std::string::npos)
            s = s.replace(pos, 1, "%20"); // 在pos处替换1个字符，将其替换为"%20"
        return s;
    }
};

/* ************************* */

namespace AnsOne {
    // Time: 0ms(100.00%)  Memory: 7.9MB(100.00%)
    class Solution {
    public:
        std::string replaceSpace(std::string s) {
            std::string res;
            for (const auto &c : s)
                if (c == ' ')
                    res += "%20";
                else
                    res += c;
            return res;
        }
    }; 
}

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->replaceSpace("We are happy.") << std::endl;
    // Ans: "We%20are%20happy."
    return EXIT_SUCCESS;
}
