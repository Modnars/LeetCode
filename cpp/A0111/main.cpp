// URL    : https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
// Author : Modnar
// Date   : 2020/02/23

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
 * 递归求解
 *     树的深度是叶子结点到根结点的距离，因此对于非叶结点需要进行判断：
 *     1. 如果结点只有左孩子/右孩子结点，那么该结点返回左子树/右子树高度+1；
 *     2. 如果结点既有左子树，又有右子树，那么该结点返回左子树和右子树最小深度+1；
 *     3. 如果某结点为空，则直接返回0。
 *     
 *     这里需要注意的就是只有一个子结点的结点，考虑到这种情况，基本就可以解决问题了。
 */
// Time: 8ms  Memory: 22.7MB
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        else if (!root->left)
            return minDepth(root->right) + 1;
        else if (!root->right)
            return minDepth(root->left) + 1;
        else
            return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << (new Solution())->minDepth(root) << std::endl;
    // Ans: 2
    return EXIT_SUCCESS;
}
