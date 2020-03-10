// URL    : https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// Author : Modnar
// Date   : 2020/03/09
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
 * 递归实现中序遍历
 */
// Time: 0ms(100.00%)  Memory: 10.4MB(11.82%)
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> ans;
        inorderVisit(ans, root);
        return ans;
    }

private:
    void inorderVisit(std::vector<int> &ans, TreeNode *root) {
        if (!root) return;
        inorderVisit(ans, root->left);
        ans.push_back(root->val);
        inorderVisit(ans, root->right);
    }
};

/* ************************* */

/**
 * 迭代求解
 *     使用辅助栈来实现二叉树中序遍历迭代实现。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 4ms(72.75%)  Memory: 9.9MB(12.86%)
    class Solution {
    public:
        std::vector<int> inorderTraversal(TreeNode *root) {
            std::vector<int> ans;
            std::vector<TreeNode *> stk;
            TreeNode *curr = root;
            while (curr || !stk.empty()) {
                while (curr) {
                    stk.emplace_back(curr);
                    curr = curr->left;
                }
                curr = stk.back();
                stk.pop_back();
                ans.emplace_back(curr->val);
                curr = curr->right;
            }
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    for (const auto &val : (new Solution())->inorderTraversal(root))
        std::cout << val << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
