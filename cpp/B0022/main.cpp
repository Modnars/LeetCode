// URL    : https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void print(ListNode *);

/* ************************* */

// Time: 0ms(100.00%)  Memory: 10.2MB(100.00%)
class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; fast && i != k; ++i)
            fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

/* ************************* */

void print(ListNode *p) {
    if (p) {
        std::cout << p->val;
        for (p = p->next; p; p = p->next)
            std::cout << " -> " << p->val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2), root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    print((new Solution())->getKthFromEnd(root, 2));
    // Ans: 4 -> 5
    print((new Solution())->getKthFromEnd(root, 1));
    // Ans: 5
    print((new Solution())->getKthFromEnd(nullptr, 0));
    // Ans: [nil]
    return EXIT_SUCCESS;
}
