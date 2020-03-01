// URL    : https://leetcode-cn.com/problems/implement-stack-using-queues/
// Author : Modnar
// Date   : 2020/03/01

#include <bits/stdc++.h>

/* ************************* */

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() { }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (empty()) return -1;
        for (int i = 0; i != data.size()-1; ++i) {
            int temp = data.front();
            data.pop();
            data.push(temp);
        }
        int ans = data.front();
        data.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return data.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }

private:
    std::queue<int> data;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    MyStack *stk = new MyStack();
    std::cout << stk->empty() << std::endl;
    // Ans: 1 (true)
    stk->push(1);
    std::cout << stk->empty() << std::endl;
    // Ans: 0 (false)
    stk->push(2);
    std::cout << stk->top() << std::endl;
    // Ans: 2
    stk->push(3);
    stk->push(4);
    std::cout << stk->top() << std::endl;
    // Ans: 4
    stk->pop();
    std::cout << stk->top() << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
