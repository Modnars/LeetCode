// URL    : https://leetcode-cn.com/problems/valid-parentheses/
// Author : Modnar
// Date   : 2020/02/21

#include <iostream>
#include <string>
#include <vector>
#include <stack>

/* ************************* */

// Time: 4ms  Memory: 8.8MB
class Solution {
public:
    bool isValid(const std::string &s) {
        std::stack<char> stk;
        for (std::string::size_type i = 0; i != s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty())
                    return false;
                switch (s[i]) {
                    case ')' :
                        if (stk.top() == '(')
                            stk.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if (stk.top() == '[')
                            stk.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if (stk.top() == '{')
                            stk.pop();
                        else
                            return false;
                        break;
                    default :
                        break;
                }
            }
        }
        return stk.empty();
    }
};

/* ************************* */

// From: wallcwr(@leetcode.cn)
namespace AnsOne {
    class Solution {
    public:
        bool isValid(const std::string &s) {
            if (s.size() % 2) return false;
            std::vector<char> vecStack;
            char c;
            for (auto i : s) {
                if (i == '}' || i == ')' || i== ']') {
                    if (!vecStack.empty()) 
                        c = vecStack[vecStack.size()-1];
                    else 
                        return false;
                    if (i == '}' && c != '{')
                        return false;
                    if (i == ')' && c != '(')
                        return false;
                    if (i == ']' && c != '[')
                        return false;
                    vecStack.pop_back();
                } else {
                    vecStack.push_back(i);
                }
            }
            return vecStack.empty();
        }
    };
}

int main(int argc, const char *argv[]) {
    std::cout << (new Solution())->isValid("()") << std::endl;
    // Ans: 1 (true)
    std::cout << (new Solution())->isValid("()[]{}") << std::endl;
    // Ans: 1 (true)
    std::cout << (new Solution())->isValid("(]") << std::endl;
    // Ans: 0 (false)
    std::cout << (new Solution())->isValid("([)]") << std::endl;
    // Ans: 0 (false)
    std::cout << (new Solution())->isValid("{[]}") << std::endl;
    // Ans: 1 (true)
    return 0;
}
