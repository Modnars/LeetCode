// URL    : https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
// Author : Modnar
// Date   : 2020/03/24

#include <bits/stdc++.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

/* ************************* */

class Solution {
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        int i = 0, j = 0, sz = preorder.size();
        if (sz == 0) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]), *temp;
        std::stack<TreeNode *> stk;
        stk.push(root);
        while (i < sz && j < sz) {
            if (stk.empty()) {
                temp->right = new TreeNode(preorder[++i]);
                stk.push(temp->right);
            }
            // if (preorder[i] != inorder[j]) {
            if (stk.top()->val != inorder[j]) {
                stk.top()->left = new TreeNode(preorder[++i]);
                stk.push(stk.top()->left);
            } else {
                temp = stk.top();
                stk.pop();
                ++j;
            }
        }
        return root;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    TreeNode *root = (new Solution())->buildTree(preorder, inorder);
    std::cout << root->val << " " << root->left->val << " " << root->right->val << " "
              << root->right->left->val << " " << root->right->right->val 
              << std::endl;
    return EXIT_SUCCESS;
}
