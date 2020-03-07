// URL    : https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
// Author : Modnar
// Date   : 2020/03/07

#include <bits/stdc++.h>

/* ************************* */

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

/**
 * 辅助队列
 *     队列中的最大值取决于队列中元素，而队列的加入顺序是“先进先出”，因而若在队列中
 * 加入了一个较大的元素，对于较其先入队的元素来说，最大的元素总为该元素。若新入队的
 * 元素较原队列中的元素更大，则可以将原队列中的元素从尾端移除，再加入这个“大元素”。
 *     考虑到上述过程的实现，可以用一个“双端队列”来实现最大值记录，并用一个队列来实现
 * 数据存储。
 *     举例来说，队列<1, 2, 3, 1, 2>，若将其绘制为一个bar图，在双端队列中需要保留的，
 * 就是一个单调递减的子序列。下面模拟这个过程：
 *     首先，元素1入队列que，此时双端队列dque为空，故将1从尾端加入dque；
 *     然后，元素2入队列que，此时dque的尾端元素1小于2，因而将1从dque尾端删除，加入2；
 *     然后，元素3入队列que，同理，dque从尾端删除2，加入3；
 *     接下来，元素1入队列que，而此时的1小于dque尾端元素3，因而直接加1加入dque；
 *     最后，元素2入队列que，此时2大于dque尾端元素1，从尾端弹出1，加入2。
 *
 *     当需要获取队列的最大值时，只需要简单地返回dque.front()即可。
 *
 *     对于最大值的更新，除了在push_back操作中，还要在pop_front中体现。当当前出队的
 * 元素等于dque.front()时，就说明队列中的最大值可能被移出队列，因而此时需要更新dque
 * 内容，即将dque前端出队。举例来说，队列<1, 1, 1, 1>在全部执行入队以后，dque的内容
 * 应当也为<1, 1, 1, 1>。
 *
 *     此外，对于本题的算法复杂度分析。尽管push_back操作看起来因有一个循环而显得复杂度
 * 似乎为O(n)，但不妨这样考虑：这个操作未必会执行。例如对于队列<1, 2, 3, 4>来说：在
 * 每次执行push_back时，dque都是执行一次尾端出队再入队新元素，因而分摊来说，每次操作的
 * 复杂度都是O(1)。
 */
// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/
// Complexity: Time: O(1)  Space: O(n)
// Time: 144ms(88.41%)  Memory: 51.4MB(100.00%)
class MaxQueue {
    std::queue<int> q;
    std::deque<int> d;

public:
    MaxQueue() { }
    
    int max_value() {
        if (d.empty()) return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value)
            d.pop_back();
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int ans = q.front();
        if (ans == d.front())
            d.pop_front();
        q.pop();
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    auto *Q = new MaxQueue();
    Q->push_back(1);
    Q->push_back(2);
    Q->push_back(1);
    std::cout << Q->max_value() << std::endl;
    // Ans: 2
    std::cout << Q->pop_front() << std::endl;
    // Ans: 1
    std::cout << Q->max_value() << std::endl;
    // Ans: 2
    std::cout << Q->pop_front() << std::endl;
    // Ans: 2
    std::cout << Q->max_value() << std::endl;
    // Ans: 1
    std::cout << std::endl;
    Q = new MaxQueue();
    std::cout << Q->pop_front() << std::endl;
    // Ans: -1
    std::cout << Q->max_value() << std::endl;
    // Ans: -1
    return EXIT_SUCCESS;
}
