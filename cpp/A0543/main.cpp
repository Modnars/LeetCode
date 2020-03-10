// URL    : https://leetcode-cn.com/problems/diameter-of-binary-tree/
// Author : Modnar
// Date   : 2020/03/10

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
 * 深度优先搜索(DFS)
 */
// Thanks: LeetCode(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/er-cha-shu-de-zhi-jing-by-leetcode-solution/
// Time: 4ms(99.47%)  Memory: 22.5MB(15.48%)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }

private:
    int ans;
    int depth(TreeNode *root) {
        if (!root) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = std::max(ans, L+R+1);
        return std::max(L, R) + 1;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    solution->diameterOfBinaryTree(root);
    return EXIT_SUCCESS;
}
