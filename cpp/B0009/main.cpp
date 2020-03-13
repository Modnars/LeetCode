// URL    : https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
// Author : Modnar
// Date   : 2020/03/13

#include <bits/stdc++.h>

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

/* ************************* */

// Time: 476ms(45.65%)  Memory: 112.4MB(100.00%)
class CQueue {
public:
    CQueue() { }
    
    // Compleity: Time: O(1)  Space: O(1)
    void appendTail(int value) {
        stk_one.push(value);
    }
    
    // Compleity: Time: O(n)  Space: O(n)
    int deleteHead() {
        if (stk_one.empty()) {
            return -1;
        } else {
            while (!stk_one.empty()) {
                stk_two.push(stk_one.top());
                stk_one.pop();
            }
            int temp = stk_two.top();
            stk_two.pop();
            while (!stk_two.empty()) {
                stk_one.push(stk_two.top());
                stk_two.pop();
            }
            return temp;
        }
    }

private:
    std::stack<int> stk_one, stk_two;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
