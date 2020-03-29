// URL    : 
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

/* ************************* */

// Time: 64ms(6.45%)  Memory: 15.2MB(100.00%)
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { }
    
    void push(int x) {
        data.emplace_back(x);
        if (helper.empty())
            helper.emplace_back(x);
        else
            helper.emplace_back(std::min(x, helper.back()));
    }
    
    void pop() {
        data.pop_back();
        helper.pop_back();
    }
    
    int top() {
        return data.empty() ? -1 : data.back();
    }
    
    int min() {
        return helper.empty() ? -1 : helper.back();
    }

private:
    std::vector<int> data, helper;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    MinStack *mstk = new MinStack();
    mstk->push(-2);
    mstk->push(0);
    mstk->push(-3);
    std::cout << mstk->min() << std::endl;
    // Ans: -3
    mstk->pop();
    std::cout << mstk->top() << std::endl;
    // Ans: 0
    std::cout << mstk->min() << std::endl;
    // Ans: -2
    return EXIT_SUCCESS;
}
