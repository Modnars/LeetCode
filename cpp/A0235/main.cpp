// URL    : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author : Modnar
// Date   : 2020/02/25
// Thanks : LeetCode(@leetcode.cn)

#include <bits/stdc++.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

/* ************************* */

/**
 * 递归
 */
// Thanks: LeetCode(@leetcode.cn)
// Time: 68ms(5.76%)  Memory: 26.1MB(5.13%)
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

/* ************************* */

/**
 * 迭代
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 36ms(88.90%)  Memory: 26MB(5.13%)
    class Solution {
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
            TreeNode *ans = root;
            while (ans) {
                if (p->val < ans->val && q->val < ans->val)
                    ans = ans->left;
                else if (p->val > ans->val && q->val > ans->val)
                    ans = ans->right;
                else
                    return ans;
            }
            return nullptr;
        }
    };
}

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
