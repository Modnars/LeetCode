// URL    : https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
// Author : Modnar
// Date   : 2020/02/26

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
 * 二叉搜索树中序遍历
 *     二叉搜索树中序遍历顺序即为数值从小到大排序，每次遍历到当前结点时，记录当前结点
 * 从小到大顺序排名，当排名为k时，记录当前结点指针，从而得解。
 *
 * 递归
 */
// Time: 44ms(8.81%)  Memory: 26.7MB(5.06%)
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        inOrderVisit(root, k);
        return ans ? ans->val : 0;
    }

private:
    int number = 0;
    TreeNode *ans = nullptr;

    void inOrderVisit(TreeNode *root, int k) {
        if (!root) return;
        inOrderVisit(root->left, k);
        ++number;
        if (number == k)
            ans = root;
        inOrderVisit(root->right, k);
    }
};

/* ************************* */

/**
 * 迭代
 *     使用辅助栈来实现迭代。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 24ms(70.06%)  Memory: 26.8MB(5.06%)
    class Solution {
    public:
        int kthSmallest(TreeNode *root, int k) {
            TreeNode *p = root;
            std::vector<TreeNode *> stk;
            while (true) {
                while (p) {
                    stk.push_back(p);
                    p = p->left;
                }
                p = stk.back();
                stk.pop_back();
                if (!--k)
                    return p->val;
                p = p->right;
            }
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    std::cout << (new Solution())->kthSmallest(root, 1) << std::endl;
    // Ans: 1
    return EXIT_SUCCESS;
}
