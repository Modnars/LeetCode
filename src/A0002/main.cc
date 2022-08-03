// File:   A0002/main.cc
// Author: modnarshen
// Date:   2022.08.03

#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* p1       = l1;
        auto* p2       = l2;
        bool over_flow = false;
        auto* ans      = new ListNode(0);
        auto p         = ans;
        while (p1 || p2) {
            auto new_val = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + (over_flow ? 1 : 0);
            over_flow    = (new_val >= 10);
            p->next      = new ListNode(new_val % 10);
            p1           = p1 ? p1->next : p1;
            p2           = p2 ? p2->next : p2;
            p            = p->next;
        }
        if (over_flow)
            p->next = new ListNode(1);
        return ans->next;
    }
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(int argc, const char* argv[]) {
    auto solution = new Solution();
    auto l1       = new ListNode{2, new ListNode{4, new ListNode{3}}};
    auto l2       = new ListNode{5, new ListNode{6, new ListNode{4}}};
    printList(solution->addTwoNumbers(l1, l2));

    l1 = new ListNode{0};
    l2 = new ListNode{0};
    printList(solution->addTwoNumbers(l1, l2));

    l1 = new ListNode{
        9, new ListNode{9, new ListNode{9, new ListNode{9, new ListNode{9, new ListNode{9, new ListNode{9}}}}}}};
    l2 = new ListNode{9, new ListNode{9, new ListNode{9, new ListNode{9}}}};
    printList(solution->addTwoNumbers(l1, l2));
    return 0;
}
