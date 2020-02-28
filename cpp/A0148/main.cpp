// URL    : https://leetcode-cn.com/problems/sort-list/
// Author : Modnar
// Date   : 2020/02/28

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
 * STL
 *     使用vector来存储链表中的所有元素，并对vector进行排序，最终将排序结果存储回
 * 链表中。
 */
// Complexity: Time: O(nlogn)  Space: O(n)
// Time: 36ms(84.04%)  Memory: 15.8MB(23.06%)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        std::vector<int> store;
        ListNode *p = head;
        while (p) {
            store.push_back(p->val);
            p = p->next;
        }
        std::sort(store.begin(), store.end());
        p = head;
        for (int i = 0; p; ++i, p = p->next)
            p->val = store[i];
        return head;
    }
};

/* ************************* */

// TODO
namespace AnsOne {
    class Solution {
    public:
        ListNode *sortList(ListNode *head) {
            if (!head || !head->next) return head;
            ListNode *fast = head->next, *slow = head;
            while (!fast && !fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *tmp = slow->next;
            slow->next = nullptr;
            ListNode *left = sortList(head);
            ListNode *right = sortList(tmp);
            ListNode *h = new ListNode(0), *res = h;
            while (left && right) {
                if (left->val < right->val) {
                    h->next = left;
                    left = left->next;
                } else {
                    h->next = right;
                    right = right->next;
                }
                h = h->next;
            }
            h->next = (left ? left : right);
            return res->next;
        }
    };
}

void print(ListNode *root) {
    if (!root) return;
    std::cout << root->val;
    for (ListNode *p = root->next; p; p = p->next)
        std::cout << " -> " << p->val;
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *root = new ListNode(4);
    root->next = new ListNode(2);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(3);
    print((new Solution())->sortList(root));
    // Ans: 1 -> 2 -> 3 -> 4
    return EXIT_SUCCESS;
}
