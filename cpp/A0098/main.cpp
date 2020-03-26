// URL    : https://leetcode-cn.com/problems/validate-binary-search-tree/
// Author : Modnar
// Date   : 2020/03/26
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
 * 中序遍历
 *     对于二叉搜索树来说，其中序遍历序列是一个升序序列。所以可以用一个cache来缓存所有
 * 结点值，最后判断chche是否是一个严格递增序列即可。
 *     有一个特殊情况，若树为空，该树依旧是一个二叉搜索树。
 */
// Time: 12ms(92.17%)  Memory: 18.5MB(100.00%)
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        dfs(root);
        for (int i = 0; i != cache.size()-1; ++i)
            if (cache[i] >= cache[i+1])
                return false;
        return true;
    }

private:
    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        cache.emplace_back(root->val);
        dfs(root->right);
    }
    std::vector<int> cache;
};

/* ************************* */

/**
 * 中序遍历
 *     使用常量空间来缓存上一个结点的值，以此来判断中序遍历顺序是否是一个升序序列。
 *     这里实现中序遍历的方式是采用辅助栈。
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Complexity: Time: O(n)  Space: O(n) // 辅助栈
    // Time: 16ms(76.32%)  Memory: 18.4MB(100.00%)
    class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            std::stack<TreeNode *> stk;
            // 定义类型为double以避免结点值为INT_MIN而出现错判
            double inorder = static_cast<double>(INT_MIN) - 1;
            while (!stk.empty() || root) {
                while (root) {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top(); stk.pop();
                if (root->val <= inorder) 
                    return false;
                inorder = root->val;
                root = root->right;
            }
            return true;
        }
    };
}

int main(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1), root->right = new TreeNode(3);
    std::cout << (new Solution())->isValidBST(root) << std::endl;
    // Ans: 1 (true)
    root = new TreeNode(5);
    root->left = new TreeNode(1), root->right = new TreeNode(4);
    root->right->left = new TreeNode(3), root->right->right = new TreeNode(6);
    std::cout << (new Solution())->isValidBST(root) << std::endl;
    // Ans: 0 (false)
    root = nullptr;
    std::cout << (new Solution())->isValidBST(root) << std::endl;
    // Ans: 1 (true)
    root = new TreeNode(1), root->left = new TreeNode(1);
    std::cout << (new Solution())->isValidBST(root) << std::endl;
    // Ans: 0 (false)
    root = new TreeNode(-2147483648);
    std::cout << (new Solution())->isValidBST(root) << std::endl;
    // Ans: 1 (true)
    return EXIT_SUCCESS;
}
