// URL    : https://leetcode-cn.com/problems/same-tree/
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
 *     使用两个队列分别对p和q进行层序遍历。遍历过程中的对子树入队操作判断两树结构是否
 * 相同，对结点值的比较来判断两树对应结点值是否相等。
 */
// Time: 0ms(100.00%)  Memory: 7.7MB(100.00%)
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        std::queue<TreeNode *> Q, H;
        if (p) Q.push(p);
        if (q) H.push(q);
        while (!Q.empty() && !H.empty()) {
            TreeNode *root = Q.front(), *temp = H.front(); 
            Q.pop(), H.pop();
            // std::cout << root->val << " " << temp->val << std::endl;
            if (root->left && temp->left) {
                Q.push(root->left);
                H.push(temp->left);
            } else if (root->left != temp->left) {
                return false;
            }
            if (root->right && temp->right) {
                Q.push(root->right);
                H.push(temp->right);
            } else if (root->right != temp->right) {
                return false;
            }
            if (root->val != temp->val)
                return false;
        }
        return Q.empty() && H.empty();
    }
};

/* ************************* */

/**
 * 深度优先搜索
 *     对两棵子树分别递归处理
 */
namespace AnsOne {
    // Thanks: LeetCode(@leetcode.cn)
    // Time: 4ms(70.50%)  Memory: 7.5MB(100.00%)
    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (!p && !q) // 如果p与q均为空指针
                return true;
            if (!p || !q) // 如果p与q中有一个为空指针
                return false;
            if (p->val != q->val) // 如果两对应结点值不相等
                return false;
            // 对两结点的左子树和右子树分别递归处理
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };
}

int main(int argc, const char *argv[]) {
    TreeNode *p = new TreeNode(1), *q = new TreeNode(1);
    p->left = new TreeNode(2), p->right = new TreeNode(3);
    q->left = new TreeNode(2), q->right = new TreeNode(3);
    std::cout << (new Solution())->isSameTree(p, q) << std::endl;
    // Ans: 1 (true)
    p->right = nullptr, q->left = nullptr, q->right->val = 2;
    std::cout << (new Solution())->isSameTree(p, q) << std::endl;
    // Ans: 0 (false)
    p->right = new TreeNode(1), q->left = new TreeNode(1);
    std::cout << (new Solution())->isSameTree(p, q) << std::endl;
    // Ans: 0 (false)
    p = new TreeNode(0), p->left = new TreeNode(1);
    q = new TreeNode(0), q->left = new TreeNode(1);
    std::cout << (new Solution())->isSameTree(p, q) << std::endl;
    // Ans: 1 (true)
    return EXIT_SUCCESS;
}
