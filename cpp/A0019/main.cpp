// URL    : https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// Author : Modnar
// Date   : 2020/03/05

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
 * 快慢双指针法
 *     令快指针先行n步，再令快慢指针同时前进，此过程保证二者每次前进都为1个结点。
 *     当快指针为nullptr时，表明快指针到达链表尾，此时慢指针所指结点即为待删除结点。
 *     对于此时的慢指针所指结点又分为以下几种情况：
 *     1. 慢指针指向链表的最后一个结点(即n=1)，此时要知道慢指针上一个结点指针才可
 * 实现题目要求，因而此时引入pre指针来记录其上一个结点指针。
 *     2. 当慢指针未前进时，此时的pre无法定义。此时对应的情况是删除的结点为头结点，
 * 此时令头结点更新为头结点的下一结点即可。
 */
// Time: 4ms(91.42%)  Memory: 12.8MB(5.28%)
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return nullptr;
        // 快指针forward, 慢指针behind, 记录指针pre。
        ListNode *forward = head, *behind = head, *pre = nullptr;
        for (int i = 0; i != n; ++i)
            forward = forward->next; // 快指针前进n步
        while (forward) {
            forward = forward->next;
            pre = behind;            // 记录待删除结点的上一结点
            behind = behind->next;
        }
        if (behind == head) {        // 若待删除结点为头结点
            ListNode *del = head;    // 缓存待删除结点
            head = head->next;       // 更新头结点。注意，此处将使得原头结点被修改！
            delete(del);             // 回收空间
        } else {
            ListNode *del = pre->next;   // 缓存待删除结点
            pre->next = pre->next->next; // 跳过待删除结点
            delete(del);                 // 回收空间
        }
        return head;
    }
};

/* ************************* */

void print(ListNode *head) {
    ListNode *p = head;
    if (!p) {
        std::cout << std::endl;
        return;
    }
    std::cout << p->val;
    p = p->next;
    while (p) {
        std::cout << " -> " << p->val;
        p = p->next;
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);
    print((new Solution())->removeNthFromEnd(head, 2));
    head = new ListNode(1);
    print(head);
    print((new Solution())->removeNthFromEnd(head, 1));
    head = new ListNode(1);
    head->next = new ListNode(2);
    print(head);
    print((new Solution())->removeNthFromEnd(head, 2));
    return EXIT_SUCCESS;
}
