// URL    : https://leetcode-cn.com/problems/swap-nodes-in-pairs/
// Author : Modnar
// Date   : 2020/03/07

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *head) {
    ListNode *p = head;
    if (p) {
        std::cout << p->val;
        p = p->next;
    }
    while (p) {
        std::cout << " -> " << p->val;
        p = p->next;
    }
    std::cout << std::endl;
}

/* ************************* */

/**
 *     使用pre和curr来缓存结点。有pre来表示已经处理完成部分的尾结点，用curr表示当前待
 * 交换的第一个结点(即交换curr和curr->next)。
 *     这里需要为pre开辟一个新的结点，以此来记录新的返回的链表。此外，需要注意的是(然
 * 而题目并没有说清楚)，当链表中结点个数为奇数时，对最后一项不需要进行交换。
 */
// Time: 0ms(100.00%)  Memory: 9.8MB(5.63%)
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // pre指向新链表中已处理完成的尾结点，curr指向待交换的第一个结点，
        // ans用于记录返回链表
        ListNode *pre = new ListNode(-1), *curr = head, *ans = pre;
        ans->next = head; // 初始化，直接将ans->next指向head
        while (curr && curr->next) {    // 只针对偶数个结点进行交换
            ListNode *p = curr->next;   // 获取curr接下来的结点
            pre->next = p;              // 记录pre的下一结点
            curr->next = p->next;       // 将p->next重新链入curr之后
            p->next = curr;             // 将p的下一结点设为curr，实现交换位置
            pre = curr;                 // 进行下一次迭代
            curr = curr->next;
        }
        return ans->next;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    print(root); // 1 -> 2 -> 3 -> 4
    print((new Solution())->swapPairs(root));
    // Ans: 2 -> 1 -> 4 -> 3
    root = new ListNode(1);
    print(root); // 1
    print((new Solution())->swapPairs(root));
    // Ans: 1
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    print(root); // 1 -> 2 -> 3
    print((new Solution())->swapPairs(root));
    // Ans: 2 -> 1 -> 3
    return EXIT_SUCCESS;
}
