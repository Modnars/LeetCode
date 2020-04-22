// URL    : https://leetcode-cn.com/problems/binary-tree-right-side-view/
// Author : Modnar
// Date   : 2020/04/22
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
// Solution: https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/er-cha-shu-de-you-shi-tu-by-leetcode-solution/
// Time: 8ms(42.88%)  Memory: 12.3MB(9.09%)
class Solution {
public:
    std::vector<int> rightSideView(TreeNode *root) {
        std::unordered_map<int, int> rightmostValueAtDepth;
        int max_depth = -1;

        std::queue<TreeNode *> nodeQueue;
        std::queue<int> depthQueue;
        nodeQueue.push(root);
        depthQueue.push(0);

        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front(); nodeQueue.pop();
            int depth = depthQueue.front(); depthQueue.pop();
            if (node != NULL) {
            	// 维护二叉树的最大深度
                max_depth = std::max(max_depth, depth);

                // 由于每一层最后一个访问到的节点才是我们要的答案，因此不断更新对应深度的信息即可
                rightmostValueAtDepth[depth] =  node -> val;
                nodeQueue.push(node -> left);
                nodeQueue.push(node -> right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }
        std::vector<int> rightView;
        for (int depth = 0; depth <= max_depth; ++depth) {
            rightView.push_back(rightmostValueAtDepth[depth]);
        }
        return rightView;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
