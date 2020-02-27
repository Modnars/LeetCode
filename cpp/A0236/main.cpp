// URL    : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Author : Modnar
// Date   : 2020/02/27
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
// Time: 16ms(96.01%)  Memory: 16.8MB(30.64%)
class Solution {
public:
    Solution() : ans(nullptr) { }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        recurseTree(root, p, q);
        return ans;
    }

private:
    TreeNode *ans;

    bool recurseTree(TreeNode *curr, TreeNode *p, TreeNode *q) {
        if (!curr) return false;
        int left = recurseTree(curr->left, p, q);
        int right = recurseTree(curr->right, p, q);
        int mid = (curr == p || curr == q);
        if (left + right + mid > 1)
            ans = curr;
        return (left + right + mid > 0);
    }
};

/* ************************* */

/**
 * 使用父指针迭代
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 44ms(11.39%)  Memory: 19.9MB(15.88%)
    class Solution {
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
            std::map<TreeNode *, TreeNode *> parent;
            std::vector<TreeNode *> stk;
            parent[root] = nullptr;
            stk.push_back(root);
            while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
                TreeNode *node = stk.back();
                stk.pop_back();
                if (node->left) {
                    parent[node->left] = node;
                    stk.push_back(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    stk.push_back(node->right);
                }
            }
            std::set<TreeNode *> ancestors;
            while (p) {
                ancestors.insert(p);
                p = parent[p];
            }
            while (ancestors.find(q) == ancestors.end())
                q = parent[q];
            return q;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5); root->right = new TreeNode(1);
    root->left->left = new TreeNode(6); root->left->right = new TreeNode(2);
    auto p = root->left->right;
    p->left = new TreeNode(7); p->right = new TreeNode(4);
    root->right->left = new TreeNode(0); root->right->right = new TreeNode(8);
    std::cout << ((new Solution())->lowestCommonAncestor(root, root->left, 
                root->right) == root) << std::endl;
    // Ans: 1 (true)
    std::cout << ((new Solution())->lowestCommonAncestor(root, p->left, p->right) 
            == p) << std::endl;
    // Ans: 1 (true)
    std::cout << ((new Solution())->lowestCommonAncestor(root, p->left, p->right) 
            == root) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
