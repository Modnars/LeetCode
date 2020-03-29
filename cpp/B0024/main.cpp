// URL    : https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
// Author : Modnar
// Date   : 2020/03/28

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *);

/* ************************* */

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *p = head, *pre = nullptr;
        while (p) {
            ListNode *next = p->next; // 记录下一个结点
            p->next = pre;            // 令当前结点的下一个结点为上一个结点
            pre = p;                  // 使当前结点作为下一轮的上一结点
            p = next;                 // 循环前进
        }
        return pre;
    }
};

/* ************************* */

void print(ListNode *p) {
    if (p) {
        std::cout << p->val;
        for (p = p->next; p; p = p->next)
            std::cout << " -> " << p->val;
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2), root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4), root->next->next->next->next = new ListNode(5);
    print((new Solution())->reverseList(root));
    return EXIT_SUCCESS;
}
