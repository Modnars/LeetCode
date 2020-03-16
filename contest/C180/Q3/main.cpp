// URL    : https://leetcode-cn.com/contest/weekly-contest-180/problems/balance-a-binary-search-tree/
// Author : Modnar
// Date   : 2020/03/15
// Thanks : 前额叶没长好(@leetcode.cn)

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
 * 中序遍历+有序数组平衡二叉树构造
 *     对于二叉搜索树来说，其中序遍历结果即为一个有序数列。因此可以将二叉搜索树的中序
 * 遍历结果存储下来，并对这个序列进行构造平衡二叉树即可。
 */
// Thanks: 前额叶没长好(@leetcode.cn)
// Complexity: Time: O(n)  Space: O(n)
// Time: 148ms(100.00%)  Memory: 45.5MB(100.00%)
class Solution {
public:
    TreeNode *balanceBST(TreeNode *root) {
        std::vector<int> data;
        inorderTravel(root, data);
        return constructBST(data, 0, data.size()-1);
    }

private:
    void inorderTravel(TreeNode *root, std::vector<int> &vec) {
        if (root == nullptr) return;
        inorderTravel(root->left, vec);
        vec.emplace_back(root->val);
        inorderTravel(root->right, vec);
    }

    TreeNode *constructBST(const std::vector<int> &vec, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + ((r - l) >> 1);
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = constructBST(vec, l, mid-1);
        root->right = constructBST(vec, mid+1, r);
        return root;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
