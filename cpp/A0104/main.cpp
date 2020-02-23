// URL    : https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

/* ************************* */

/**
 * 递归求解
 *     返回结点的左子树和右子树最大值＋1即可。
 */
// Time: 20ms  Memory: 21.8MB
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        else
            return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << (new Solution())->maxDepth(root) << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
