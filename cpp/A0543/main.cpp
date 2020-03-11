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
 *     使用DFS求以结点node为子树根结点的最大深度(包括当前结点和叶子结点)。由此可知，
 * 结点node的左子树最大深度L = depth(node->left)；右子树最大深度R = depth(node->
 * right)，那么由此可知此时可计算的最大直径为L+R+1，即求和且加入当前结点后得到的
 * 结果值，需要注意的是，这个结果值为最大直径上的结点数，因而要求直径值，要减去一。
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
