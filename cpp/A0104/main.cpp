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

/**
 * 迭代求解
 *     广度优先搜索(BFS)
 */
namespace AnsOne {
    // Thanks: 一剑飘虹刹九洲(@csdn.cn)
    // Time: 8ms(93.30%)  Memory: 20.3MB(5.11%)
    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            std::queue<TreeNode *> store;
            int depth = 0;
            if (root) store.push(root); // 根结点入队
            while (!store.empty()) {    // 当队列为空时退出循环
                ++depth;                // 遍历到当前层，令深度加一
                int len = store.size(); // 记录当前层的结点数
                while (len--) {         // 将这些结点的子结点入队，并弹出当前层结点
                    TreeNode *curr = store.front();
                    store.pop();
                    if (curr->left) 
                        store.push(curr->left);  // 左孩子结点入队
                    if (curr->right) 
                        store.push(curr->right); // 右孩子结点入队
                }
            }
            return depth;
        }
    };
}

/**
 * 迭代求解
 *     深度优先搜索(DFS)
 */
namespace AnsTwo {
    // Thanks: IceinCloud(@csdn.cn)
    // Time: 8ms(93.30%)  Memory: 21.2MB(5.11%)
    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            std::stack<std::pair<TreeNode *, int>> stk;
            int depth = 0;
            if (root) stk.push(std::make_pair(root, 1));
            while (!stk.empty()) {
                TreeNode *curr = stk.top().first;
                int curr_depth = stk.top().second;
                depth = std::max(depth, curr_depth);
                stk.pop();
                if (curr->right)
                    stk.push(std::make_pair(curr->right, curr_depth+1));
                if (curr->left)
                    stk.push(std::make_pair(curr->left, curr_depth+1));
            }
            return depth;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << (new Solution())->maxDepth(root) << std::endl;
    // Ans: 3
    return EXIT_SUCCESS;
}
