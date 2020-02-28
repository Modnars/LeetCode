// URL    : https://leetcode-cn.com/problems/linked-list-cycle-ii/
// Author : Modnar
// Date   : 2020/02/28
// Thanks : Krahets(@leetcode.cn)

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

/* ************************* */

/**
 * 借助辅助set来检查结点是否已经遍历过，如果遍历过，将其直接返回；否则将其加入集合，
 * 继续遍历下一个结点。
 */
// Complexity: Time: O(n)  Space: O(n)
// Time: 28ms(12.75%)  Memory: 12.2MB(5.22%)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        std::set<ListNode *> check;
        while (p) {
            if (check.find(p) == check.end())
                check.insert(p);
            else
                return p;
            p = p->next;
        }
        return p;
    }
};

/* ************************* */

/**
 * 快慢指针
 *     使用快慢指针来帮助寻找环的入口。如果令快指针每次前进“两步”，慢指针每次前进
 * “一步”，那么当二者首次相遇时，有快指针比慢指针多走了n圈，其数学关系式可表示为：
 *                      len(fast) = len(slow) + n * len(circle)
 *     而相同时间内，快指针走过的长度是慢指针走过长度的二倍，也就是有：
 *                      len(fast) = 2 * len(slow)
 *     化简得：
 *                      len(slow) = n * len(circle)
 *     也就是说，当二者首次相遇时，慢指针刚好走了circle的整数倍的长度。而如果慢指针从
 * 起点走到环入口结点处，其走过的距离应当为len(slow) = a + n * len(circle)。由此可知，
 * 当快慢指针首次相遇时，慢指针再走距离a就可以回到环入口结点处(其中a为从起点到环入口
 * 结点的距离)。该如何实现呢？可以令此时的快指针置于链表头，令快指针每次前进“一步”，
 * 那么当快指针走完距离a，快指针应当到达环入口结点；此时慢指针也走了a，其总距离为
 * n * len(circle) + a正好也是慢指针走回到环入口结点的距离，此时快慢指针第二次相遇，
 * 此时二者即相遇在环入口结点处。
 */
namespace AnsOne {
    // Thanks: Krahets(@leetcode.cn)
    // Complexity: Time: O(n)  Space: O(1)
    // Time: 16ms(56.00%)  Memory: 9.8MB(26.34%)
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (!head || !head->next) return nullptr;
            ListNode *fast = head->next->next, *slow = head->next;
            while (fast != slow) {
                if (!fast || !fast->next)
                    return nullptr;
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    ListNode *root = new ListNode(3), *p = new ListNode(2);
    root->next = p; p->next = new ListNode(0);
    p->next->next = new ListNode(-4);
    p->next->next->next = p;
    std::cout << ((new Solution())->detectCycle(root) == p) << std::endl;
    // Ans: 1 (true)
    return EXIT_SUCCESS;
}
