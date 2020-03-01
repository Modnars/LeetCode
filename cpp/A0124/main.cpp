// URL    : https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
// Author : Modnar
// Date   : 2020/03/01
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

// Thanks: LeetCode(@leetcode.cn)
// Complexity: Time: O(N)  Space: O(logN)  N为结点个数
// Time: 24ms(97.96%)  Memory: 31.9MB(5.07%)
class Solution {
public:
    Solution() : max_sum(INT_MIN) { }

    int maxPathSum(TreeNode *root) {
        max_gain(root);
        return max_sum;
    }

private:
    int max_sum;

    int max_gain(TreeNode *node) {
        if (!node) return 0;
        // 记录当前结点左子树和右子树的最大收益值
        int left_gain = std::max(max_gain(node->left), 0);
        int right_gain = std::max(max_gain(node->right), 0);
        // 尝试将当前结点加入最大路径中
        int price_newpath = node->val + left_gain + right_gain;
        // 更新当前结点加入后的最大路径和
        max_sum = std::max(max_sum, price_newpath);
        // 递归结果:
        // 返回若继续相同路径而获得的最大收益值
        return node->val + std::max(left_gain, right_gain);
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::cout << (new Solution())->maxPathSum(root) << std::endl;
    // Ans: 6
    root = new TreeNode(-10);
    root->left = new TreeNode(9); root->right = new TreeNode(20);
    root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);
    std::cout << (new Solution())->maxPathSum(root) << std::endl;
    // Ans: 42
    root->left->val = -9; root->right->val = -20;
    root->right->left->val = -15; root->right->right->val = -7;
    std::cout << (new Solution())->maxPathSum(root) << std::endl;
    // Ans: -7
    return EXIT_SUCCESS;
}
