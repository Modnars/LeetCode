// URL    : https://leetcode-cn.com/problems/min-stack/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : liweiwei1419(@leetcode.cn)

#include <bits/stdc++.h>

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* ************************* */

/**
 * 辅助栈
 *     使用辅助栈来存储输入x时，数据栈的最小值。数据栈和辅助栈的动作保持同步。
 */
// Thanks: liweiwei1419(@leetcode.cn)
// Time: 28ms(89.63%)  Memory: 17.7MB(5.03%)
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { }
    
    void push(int x) {
        data.push_back(x);
        if (!helper.empty()) {
            int min_value = helper.back();
            helper.push_back(x < min_value ? x : min_value);
        } else {
            helper.push_back(x);
        }
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_back();
            helper.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return helper.back();
    }

private:
    std::vector<int> helper;
    std::vector<int> data;
};

/* ************************* */

/**
 * 使用min_value并使用策略存储其值
 *     使用min_value来存储最小值。在push中，若x的值不大于min_value，则将min_value压入
 * 栈中，再执行栈操作(即将x压入栈)；否则只执行常规栈操作即可。
 *     相应地，在pop中，若栈顶值和min_value相等，则更新min_value为次栈顶元素，并执行
 * 栈操作(即将栈顶元素弹出)；否则只执行常规栈操作即可。
 *
 * 需要注意的是，对于空栈的可能情况，需要注意正确定义其动作。
 *
 * 分析可知，这种情况能够较双栈(数据栈+辅助栈)节省空间。但是对于按从大到小顺序输入的
 * 情况，其所占空间和双栈情况基本一致。
 */
namespace AnsOne {
    // Time: 20ms(99.43%)  Memory: 17.6MB(5.03%)
    class MinStack {
    public:
        /** initialize your data structure here. */
        MinStack() { }
        
        void push(int x) {
            if (data.empty()) {
                min_value = x;
            } else if (x <= min_value) {
                data.push_back(min_value);
                min_value = x;
            }
            data.push_back(x);
        }
        
        void pop() {
            if (!data.empty()) {
                bool update = (min_value == data.back());
                data.pop_back();
                if (update && !data.empty()) {
                    min_value = data.back();
                    data.pop_back();
                }
            }
        }
        
        int top() {
            return data.back();
        }
        
        int getMin() {
            return min_value;
        }

    private:
        int min_value;
        std::vector<int> data;
    };
}

int main(int argc, const char *argv[]) {
    using MinStack = AnsOne::MinStack;
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl;
    // Ans: -3
    minStack->pop();
    std::cout << minStack->top() << std::endl;
    // Ans: 0
    std::cout << minStack->getMin() << std::endl;
    // Ans: -2
    minStack = new MinStack();
    minStack->push(0);
    minStack->push(1);
    minStack->push(0);
    std::cout << minStack->getMin() << std::endl;
    // Ans: -2
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    // Ans: -2
    return EXIT_SUCCESS;
}
