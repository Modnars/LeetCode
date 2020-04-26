// URL    : https://leetcode-cn.com/problems/merge-k-sorted-lists/
// Author : Modnar
// Date   : 2020/02/21

// ✅ : 2020/04/26

#include <iostream>
#include <climits>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *);

/* ************************* */

/**
 * 这是一道典型的考察对指针理解程度的题目。
 *     这里的基本想法是，遍历数组内所有指针(即头指针)，选出val属性最小的头指针，将该结
 * 点链入新的结果链表中；同时，修改数组中被选出的头指针所在位置，使该位置存放头指针的
 * next指针。由此可知，循环终止的条件就是数组中所剩下的所有指针均为空指针。
 *
 *     值得注意的是，如何修改数组中的指针所在位置，使其存放指针的next指针。这里采用的
 * 是获取被修改位置的下标(idx)，以此获得数组中需要修改位置的引用(即lists[idx])。此外，
 * 如何筛选出val最小的指针值得考究，这里是令临时存放指针(p)在每次筛选前均指向一个拥有
 * 极大val的结点，从而达到目的。由于这个p仅是数组中一些指针的临时拷贝，所以我们无法
 * 利用p来做最后的修改数组内容的引用。当然，由于C++中的引用不允许动态绑定，所以用p来
 * 修改的目的根本无法达成，这也是引入了idx的重要原因。
 *
 *     分析可知，上述算法对lists中每个链表的每个结点均遍历了一次，故算法时间复杂度为
 * O(n*m)，其中n为lists中链表个数，m为lists中最长链表长度。
 *
 * 注: 上述数组是指vector，即代码中的lists。
 */
// Time: 1144ms(5.07%)  Memory: 10.2MB(100.00%)
class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        ListNode *ans = new ListNode(0x7FFFFFFF), *p = ans, *current = ans;
        std::vector<ListNode *>::size_type idx = 0;
        bool hasNode = true;
        while (hasNode) {
            hasNode = false;
            p = ans; // 令p始终指向最大的可能值
            for (std::vector<ListNode *>::size_type i = 0; i != lists.size(); ++i)
                if (lists[i] && lists[i]->val < p->val) {
                    idx = i;        // 记录val最小的结点所在lists中位置
                    p = lists[i];   // 为了后序筛选，临时存放这个结点的指针
                    hasNode = true; // 标记ans需要继续添加结点且循环需要继续
                }
            if (hasNode) {
                current->next = lists[idx];     // 将lists[idx]链入ans尾
                current = current->next;        // 修改current使其指向ans尾结点
                lists[idx] = lists[idx]->next;  // 修改lists[idx]使其指向其下一结点
            }
        }
        return ans->next;
    }
};

/* ************************* */

void print(ListNode *ln) {
    ListNode *p = ln;
    if (p)
        std::cout << p->val;
    p = p->next;
    while (p) {
        std::cout << " -> " << p->val;
        p = p->next;
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
    std::vector<ListNode *> lists;
    lists.push_back(new ListNode(1));
    lists.back()->next = new ListNode(4);
    lists.back()->next->next = new ListNode(5);
    lists.push_back(new ListNode(1));
    lists.back()->next = new ListNode(3);
    lists.back()->next->next = new ListNode(4);
    lists.push_back(new ListNode(2));
    lists.back()->next = new ListNode(6);
    print((new Solution())->mergeKLists(lists));
    return 0;
}
