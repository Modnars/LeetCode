// URL    : https://leetcode-cn.com/problems/middle-of-the-linked-list/
// Author : Modnar
// Date   : 2020/03/23

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

/* ************************* */

/**
 * 快慢指针
 */
// Time: 0ms(100.00%)  Memory: 8.2MB(100.00%)
class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *fast = head->next, *slow = head;
        while (fast) {
            fast = fast->next;
            if (fast)
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    ListNode *li = new ListNode(1);
    li->next = new ListNode(2);
    li->next->next = new ListNode(3);
    li->next->next->next = new ListNode(4);
    li->next->next->next->next = new ListNode(5);
    std::cout << (new Solution())->middleNode(li)->val << std::endl;
    // Ans: 3
    li->next->next->next->next->next = new ListNode(6);
    std::cout << (new Solution())->middleNode(li)->val << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
