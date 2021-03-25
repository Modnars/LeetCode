// URL    : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Modnar
// Date   : 2021/03/25

#include <bits/stdc++.h>

/* ************************* */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        std::map<int, int> store;
        auto ptr = head;
        while (ptr) {
            ++store[ptr->val];
            ptr = ptr->next;
        }
        ptr = head;
        auto ans = new ListNode();
        ans->next = head;
        auto zip = ans;
        while (zip) {
            while (ptr && store[ptr->val] > 1) {
                ptr = ptr->next;
            }
            zip->next = ptr;
            zip = zip->next;
            if (ptr) {
                ptr = ptr->next;
            }
        }
        return ans->next;
    }
};

// From LeetCode
namespace AnsOne {
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0, head);

        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
}

/* ************************* */

ListNode *construct_list(const std::vector<int> &vals) {
    ListNode *head = new ListNode();
    auto ptr = head;
    for (const auto &val : vals) {
        ptr->next = new ListNode(val);
        ptr = ptr->next;
    }
    return head->next;
}

void print_list(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(int argc, char *const argv[]) {
    print_list((new AnsOne::Solution())->deleteDuplicates(construct_list({1, 2, 3, 3, 4, 4, 5})));
    print_list((new AnsOne::Solution())->deleteDuplicates(construct_list({1, 1, 1, 2, 3})));
    return EXIT_SUCCESS;
}

