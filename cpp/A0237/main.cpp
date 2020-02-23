// URL    : https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

/* ************************* */

/**
 * 换个思维
 *     这道题只是要个结果，所以事实上真正删除掉了哪个结点“不重要”！这道题思维很巧妙，
 * 只给定“待删除”的结点指针，所以不妨换个思维：
 *     将下一个结点的信息另存到当前结点，并将下一个结点删除即可。需要注意的就是一定要
 * 将下一个结点的下一个结点链接到当前结点后。
 */
// Time: 12ms  Memory: 9.5MB
class Solution {
public:
    void deleteNode(ListNode *node) {
        ListNode *p = node->next;
        node->val = p->val;
        node->next = p->next;
        delete(p);
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
