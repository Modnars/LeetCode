// URL    : https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : 王小二(@leetcode.cn)

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

/* ************************* */

// Time: 88ms  Memory: 20.4MB
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode *> nodeSet;
        ListNode *p = headA, *q = headB;
        while (p) {
            nodeSet.insert(p);
            p = p->next;
        }
        for ( ; q && nodeSet.find(q) == nodeSet.end();q = q->next)
            ;
        return q;
    }
};

/* ************************* */

namespace AnsOne {
    // STATUS: Failed
    // Thanks: LeetCode(@leetcode.cn)
    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *p = headA, *q = headB, *tailA = nullptr, *tailB = nullptr;
            if (!p || !q) return nullptr;
            bool onLineA = true, onLineB = true;
            while (p != q) {
                if (!p) {
                    if (!onLineA) break;
                    onLineA = false;
                    p = headB;
                }
                if (!q) {
                    if (!onLineB) break;
                    onLineB = false;
                    q = headA;
                }
                if (onLineA && p->next == nullptr)
                    tailA = p;
                if (onLineB && q->next == nullptr)
                    tailB = q;
                p = p->next;
                q = q->next;
            }
            if (tailA == tailB)
                return tailA;
            return p;
        }
    };
}

/**
 * 双指针
 *     算法如下：
 *     1. 指针 pA 指向 A 链表，指针 pB 指向 B 链表，依次往后遍历；
 *     2. 如果 pA 到了末尾，则 pA = headB 继续遍历；
 *     3. 如果 pB 到了末尾，则 pB = headA 继续遍历；
 *     4. 比较长的链表指针指向较短链表head时，长度差就消除了。
 *     值得一提的是，两个链表的尾结点的next为nullptr，当二者没有相同结点时，会在遍历
 * 两次结束后，同时到达nullptr而退出循环结束程序。
 *     如此，只需要将最短链表遍历两次即可找到位置
 */
namespace AnsTwo {
    // Thanks: 王小二(@leetcode.cn)
    // Time: 52ms  Memory: 16.8MB
    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *ha = headA, *hb = headB;
            while (ha != hb) {
                ha = ha ? ha->next : headB;
                hb = hb ? hb->next : headA;
            }
            return ha;
        }
    };
}

int main(int argc, const char *argv[]) {
    ListNode *intersection = new ListNode(8);
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersection;
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection;
    std::cout << ((new Solution())->getIntersectionNode(headA, headB) == intersection)
              << std::endl;
    // Ans: 1 (true)
    return EXIT_SUCCESS;
}
