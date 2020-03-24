// URL    : https://leetcode-cn.com/problems/merge-two-sorted-lists/
// Author : Modnar
// Date   : 2020/02/21

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *);

/* ************************* */

// Time: 8ms  Memory: 17.1MB
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(-1), *p = l1, *q = l2, *r = ans;
        while (p && q) {
            if (p->val < q->val) {
                r->next = new ListNode(p->val);
                p = p->next;
            } else {
                r->next = new ListNode(q->val);
                q = q->next;
            }
            r = r->next;
        }
        while (p) {
            r->next = new ListNode(p->val);
            r = r->next;
            p = p->next;
        }
        while (q) {
            r->next = new ListNode(q->val);
            r = r->next;
            q = q->next;
        }
        return ans->next;
    }
};

/* ************************* */

// Time: 8ms  Memory: 16.8MB
namespace AnsOne {
    /**
     *     为了减少空间开销，可以将链表q的结点拆解并链入链表p上，这里的p和q是根据l1和
     * l2的头结点决定的。若l1->val < l2->val，则p = l1、q = l2；否则，相反。
     *     不妨称被链入的链为“主链”(最终作为返回值返回)，待链入的链表称为“副链”。
     *     代码中ans指向主链，pre指向主链已确定部分的尾结点，p指向主链未确定部分的首
     * 结点，q指向副链待链入结点。
     *     由此可知，算法就是动态更新pre所指结点，并确定将p还是q链入pre结点之后。
     *
     *     需要说明的是，执行这个函数后，原函数中的l1、l2将被破坏(因为原链被拆分)，故
     * 不作为默认题解。
     */
    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if (!l1) return l2;
            if (!l2) return l1;
            // pre指向主链的已确定部分尾结点，ans记录主链头
            ListNode *p = (l1->val < l2->val) ? l1 : l2,
                     *q = (l1->val >= l2->val) ? l1 : l2, 
                     *pre = p, *ans = p; 
            if (!p->next) {
                p->next = q; // 如果主链只有一个结点，则将副链直接链接到其后
                return p;
            }
            p = p->next;    // 否则令p指向其next指针所指结点
            while (q) {     // 如果被拆分的副链仍有结点，循环继续
                if (!p) { 
                    // 如果循环过程中主链结点已遍历尽，则将剩余副链结点链入主链尾
                    pre->next = q; 
                    break;
                }
                if (q->val < p->val) { // 若副链待链入结点val值小于主链待确定结点val值
                    pre->next = q;     // 将副链待链入结点链入
                    q = q->next;       // 更新副链待链入结点指针 
                    pre->next->next = p;    // 将插入的结点放在p所指结点之前
                } else {
                    p = p->next; // 否则主链待确定结点变为确定链入主链结点
                }
                pre = pre->next; // 每轮更新均有一个结点加入，故更新pre
            }
            return ans;
        }
    };
}

void print(ListNode *ln) {
    if (ln) {
        std::cout << ln->val;
        ln = ln->next;
    }
    while (ln) {
        std::cout << " -> " << ln->val;
        ln = ln->next;
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    print((new Solution())->mergeTwoLists(l1, l2));
    return 0;
}
