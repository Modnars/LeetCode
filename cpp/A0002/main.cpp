// URL    : https://leetcode-cn.com/problems/add-two-numbers/
// Author : Modnar
// Date   : 2020/02/20
// Thanks : Hao Chen(@github:haoel)

#include <cstdlib>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(struct ListNode *ln);

/* ************************* */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1), *h = head;
        ListNode *p = l1, *q = l2;
        int sum = 0, carry = 0;
        while (p || q) {
            sum = 0;
            if (p) {
                sum += p->val;
                p = p->next;
            }
            if (q) {
                sum += q->val;
                q = q->next;
            }
            sum += carry;
            carry = sum / 10;
            h->next = new ListNode(sum%10);
            h = h->next;
        }
        if (carry)
            h->next = new ListNode(carry);
        return head->next;
    }
};

/* ************************* */

void print(struct ListNode *ln) {
    while (ln) {
        std::cout << ln->val;
        ln = ln->next;
    }
    std::cout << std::endl;
}

int main(int ac, char *av[]) {
    struct ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    struct ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    print((new Solution())->addTwoNumbers(l1, l2));
    return 0;
}
