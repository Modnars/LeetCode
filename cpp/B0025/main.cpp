// URL    : https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
// Author : Modnar
// Date   : 2020/03/24
// SameTo : A0021

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *);

/* ************************* */

// Time: 28ms(34.50%)  Memory: 17.4MB(100.00%)
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2, *ans = new ListNode(-1), *r = ans;
        while (p && q) {
            if (p->val < q->val) {
                r->next = p;
                p = p->next;
                r = r->next;
            } else {
                r->next = q;
                q = q->next;
                r = r->next;
            }
        }
        if (p)
            r->next = p;
        if (q)
            r->next = q;
        return ans->next;
    }
};

/* ************************* */

void print(ListNode *l) {
    if (l) {
        std::cout << l->val;
        ListNode *p = l->next;
        while (p) {
            std::cout << " -> " << p->val;
            p = p->next;
        }
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    ListNode *l1 = new ListNode(1), *l2 = new ListNode(1);
    l1->next = new ListNode(2), l1->next->next = new ListNode(4);
    l2->next = new ListNode(3), l2->next->next = new ListNode(4);
    print((new Solution())->mergeTwoLists(l1, l2));
    return EXIT_SUCCESS;
}
