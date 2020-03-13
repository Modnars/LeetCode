// URL    : https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
// Author : Modnar
// Date   : 2020/03/13

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

/* ************************* */

// Complexity: Time: O(n)  Space: O(1)
// Time: 140ms(5.21%)  Memory: 10.3MB(100.00%)
class Solution {
public:
    std::vector<int> reversePrint(ListNode *head) {
        std::vector<int> ans;
        ListNode *p = head;
        while (p) {
            ans.insert(ans.begin(), p->val);
            p = p->next;
        }
        return ans;
    }
};

/* ************************* */

/**
 * 全部加入数组中并翻转
 *     需要注意的是，这种写法和默认解的区别在于使用insert还是emplace_back，可以看到，
 * 后者效率较前者更高。
 */
namespace AnsOne {
    // Complexity: Time: O(n)  Space: O(1)
    // Time: 8ms(66.99%)  Memory: 11.2MB(100.00%)
    class Solution {
    public:
        std::vector<int> reversePrint(ListNode *head) {
            std::vector<int> ans;
            ListNode *p = head;
            while (p) {
                ans.emplace_back(p->val);
                p = p->next;
            }
            for (int i = 0, j = ans.size()-1; i < j; ++i, --j)
                if (ans[i] != ans[j])
                    std::swap(ans[i], ans[j]);
            return ans;
        }
    };
}

/**
 * 使用栈
 */
namespace AnsTwo {
    // Time: 12ms(29.92%)  Memory: 10.3MB(100.00%)
    class Solution {
    public:
        std::vector<int> reversePrint(ListNode *head) {
            std::vector<int> ans;
            std::stack<int> stk;
            ListNode *p = head;
            while (p) {
                stk.push(p->val);
                p = p->next;
            }
            while (!stk.empty()) {
                ans.emplace_back(stk.top());
                stk.pop();
            }
            return ans;
        }
    };
}

/**
 * 递归
 */
namespace AnsThree {
    // Time: 8ms(66.99%)  Memory: 10.6MB(100.00%)
    class Solution {
    public:
        std::vector<int> reversePrint(ListNode *head) {
            std::vector<int> ans;
            recursive(ans, head);
            return ans;
        }

    private:
        void recursive(std::vector<int> &nums, ListNode *node) {
            if (!node) return;
            recursive(nums, node->next);
            nums.emplace_back(node->val);
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsThree::Solution;
    Solution *solution = new Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    for (const auto &val : solution->reversePrint(head))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
