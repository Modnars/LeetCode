// URL    : https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// Author : Modnar
// Date   : 2020/05/13

#include <bits/stdc++.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

/* ************************* */

// Time: 12ms(17.52%)  Memory: 11.5MB(100.00%)
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::queue<TreeNode *> Q;
        TreeNode *p = nullptr;
        std::vector<std::vector<int>> ans;
        if (root) {
            Q.push(root);
        }
        while (!Q.empty()) {
            ans.emplace_back(std::vector<int>());
            int count = Q.size();
            for (int i = 0; i != count; ++i) {
                p = Q.front();
                ans.back().emplace_back(p->val);
                if (p->left) {
                    Q.push(p->left);
                }
                if (p->right) {
                    Q.push(p->right);
                }
                Q.pop();
            }
        }
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9); root->right = new TreeNode(20);
    root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);
    for (const auto &row : (new Solution())->levelOrder(root)) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
