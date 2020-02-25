// URL    : https://leetcode-cn.com/problems/reverse-linked-list/
// Author : Modnar
// Date   : 2020/02/25

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *head) {
    for (auto *h = head; h; h = h->next)
        std::cout << h->val << " ";
    std::cout << std::endl;
}

/* ************************* */

// Algorithm: 迭代
// Time: 4ms  Memory: 10.2MB
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = head, *prev = nullptr;
        while (curr) {
            ListNode *next = curr->next; // 记录当前节点的下一个结点
            curr->next = prev;            // 当前结点的next指针指向前一个结点
            prev = curr;                  // 更新prev指针指向当前结点
            curr = next;                 // 更新curr使其指向下个待处理结点
        }
        // 处理结束后，curr为空，此时prev指向原链表最后一个结点，也就是新链表的第一个结点
        return prev;
    }
};

/* ************************* */

namespace AnsOne {
    // Algorithm: 递归
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 4ms  Memory: 10.5MB
    class Solution {
    public:
        ListNode *reverseList(ListNode *head) {
            // 若当前结点的next指针为空(针对原尾结点)，将结点直接返回
            if (!head || !head->next)
                return head;
            ListNode *p = reverseList(head->next); // 使用p来传递新链表的头指针
            head->next->next = head;               // 修改下一结点的next指针指向自己
            // 将当前结点的next置为空指针，以避免因原链表头结点next指针未修改而出现环
            head->next = nullptr;
            return p;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);
    print((new Solution())->reverseList(head));
    return EXIT_SUCCESS;
}
