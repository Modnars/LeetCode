// URL    : https://leetcode-cn.com/contest/weekly-contest-180/problems/design-a-stack-with-increment-operation/
// Author : Modnar
// Date   : 2020/03/15

#include <bits/stdc++.h>

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

/* ************************* */

class CustomStack {
public:
    CustomStack(int maxSize) : capacity(maxSize) { }
    
    void push(int x) {
        if (data.size() >= capacity) return;
        data.emplace_back(x);
    }
    
    int pop() {
        if (data.empty()) return -1;
        int val = data.back();
        data.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i != k && i != data.size(); ++i)
            data[i] += val;
    }

private:
    int capacity;
    std::vector<int> data;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
