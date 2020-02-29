// URL    : https://leetcode-cn.com/problems/rotate-list/
// Author : Modnar
// Date   : 2020/02/29

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *);

/* ************************* */

/**
 * 双指针法
 *     首先计算链表长度，然后将front指针放置在链表头，向前走k步。此时使behind指针指向
 * 头结点，然后让front、behind同时前进，直到front指针指向尾结点，可知此时behind指针指
 * 向的就是新的链表的尾结点。将原链表behind下一结点记录，并自behind后切断，同时将
 * head指针链入此时的front之后，返回记录即可。
 */
// Complexity: Time: O(n)  Space: O(1)
// Time: 12ms(40.95%)  Memory: 13.6MB(5.13%)
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return nullptr;
        ListNode *front = head, *behind = head;
        int len = 0;
        for ( ; front; front = front->next) // 统计链表长度
            ++len;
        k %= len; // 确定front需要先前进的步数
        if (k == 0) return head;
        front = head;
        while (k--) // front前进k步
            front = front->next;
        while (front->next) { // front和behind同时前进
            front = front->next;
            behind = behind->next;
        }
        ListNode *ans = behind->next;   // 记录新链表头结点指针
        front->next = head;             // 将head链入front之后
        behind->next = nullptr;         // 将原链表拆开
        return ans;
    }
};

/* ************************* */

/**
 * 成环+破环
 *     将链表的尾结点后接头结点成环，再在合适的位置将换拆为链。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 20ms(5.54%)  Memory: 13.6MB(5.13%)
    class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (!head || k == 0) return head;
            ListNode *p = head, *ans;
            int len = 1;
            for ( ; p->next; p = p->next) // 统计链表结点数，并使p指向尾结点
                ++len;
            p->next = head; // 使链表成环
            p = head;       // 将p指向头结点
            for (int i = 0; i != len-k%len-1; ++i) // 使p指向新的链表的尾结点
                p = p->next;
            ans = p->next; p->next = nullptr; // 记录需返回的新链表头，破环
            return ans;
        }
    };
}

void print(ListNode *head) {
    ListNode *p = head;
    if (p) {
        std::cout << p->val;
        p = p->next;
    }
    for ( ; p; p = p->next)
        std::cout << " -> " << p->val;
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);
    print((new Solution())->rotateRight(head, 2));
    // Ans: 4 -> 5 -> 1 -> 2 -> 3
    head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    print(head);
    print((new Solution())->rotateRight(head, 4));
    // Ans: 2 -> 0 -> 1
    return EXIT_SUCCESS;
}
