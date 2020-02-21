// URL    : https://leetcode-cn.com/problems/palindrome-linked-list/
// Author : Modnar
// Date   : 2020/02/21
// Thanks : hello_pretty(@leetcode.cn)

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* ************************* */

/**
 * 使用“栈”的“先进后出”原理，将链表中所有元素压入栈，再将元素逐个出栈与链表元素对比。
 * 这里使用vector来实现“栈”的动作。
 **/
// Time: 28ms  Memory: 17MB
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *h = head;
        std::vector<int> data;
        while (h) {
            data.push_back(h->val);
            h = h->next;
        }
        h = head;
        for (auto iter = data.crbegin(); iter != data.crend(); ++iter, h = h->next)
            if (*iter != h->val)
                return false;
        return true;
    }
};

/* ************************* */

/**
 * 用快慢指针遍历的同时翻转前半部分，然后与后半部分比较即可。
 */
// From: hello_pretty(@leetcode.cn)
// Time: 16ms  Memory: 15.9MB
namespace AnsOne {
    class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(!head || !head->next)
                return 1;
            ListNode *fast = head, *slow = head;
            ListNode *p, *pre = NULL;
            while (fast && fast->next) {
                p = slow;
                slow = slow->next; //快慢遍历
                fast = fast->next->next;
                p->next = pre; //翻转
                pre = p;
            }
            if (fast) //奇数个节点时跳过中间节点
                slow = slow->next;
            while (p) {       //前半部分和后半部分比较
                if (p->val != slow->val)
                    return 0;
                p = p->next;
                slow = slow->next;
            }
            return 1;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    std::cout << (new Solution())->isPalindrome(head) << std::endl;
    // Ans: 0 (false)
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    std::cout << (new Solution())->isPalindrome(head) << std::endl;
    // Ans: 1 (true)
    return 0;
}
