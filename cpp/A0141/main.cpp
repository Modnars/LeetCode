// URL    : https://leetcode-cn.com/problems/linked-list-cycle/
// Author : Modnar
// Date   : 2020/02/25

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
 *     当某一时刻快指针为nullptr时，判定链表不存在环；当某一时刻快慢指针重合时，判定
 * 链表存在环。
 */
// Time: 8ms(97.65%)  Memory: 9.9MB(20.99%)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

/**
 * 集合查重
 *     当然也可以使用unordered_set来作为检查容器，但由于哈希表的加入，向其中加入元素
 * 的操作可能会影响时间性能。
 */
namespace AnsOne {
    // Time: 28ms(10.65%)  Memory: 12.2MB(5.20%)
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            std::set<ListNode *> check;
            ListNode *h = head;
            while (h) {
                if (check.find(h) != check.end())
                    return true;
                else
                    check.insert(h);
                h = h->next;
            }
            return false;
        }
    };
}

/* ************************* */

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *head = new ListNode(3), *point = new ListNode(2);
    head->next = point;
    point->next = new ListNode(0);
    point->next->next = new ListNode(-4);
    point->next->next->next = point;
    std::cout << (new Solution())->hasCycle(head) << std::endl;
    // Ans: 1 (true)
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
    std::cout << (new Solution())->hasCycle(head) << std::endl;
    // Ans: 1 (true)
    head = new ListNode(1);
    std::cout << (new Solution())->hasCycle(head) << std::endl;
    // Ans: 0 (false)
    std::cout << (new Solution())->hasCycle(nullptr) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
