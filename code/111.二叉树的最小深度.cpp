/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 层序遍历
    // int minDepth(TreeNode* root) {
    //     if(root == nullptr) {
    //         return 0;
    //     }
    //     int level = 1;
    //     queue<TreeNode*> nodeQue;
    //     nodeQue.push(root);
    //     while(!nodeQue.empty()) {
    //         int levelSize = nodeQue.size();
    //         TreeNode *node = nullptr;
    //         for(int i = 0; i < levelSize; ++i) {
    //             node = nodeQue.front();
    //             nodeQue.pop();
    //             if(node->left == nullptr && node->right == nullptr) {
    //                 return level;
    //             }
    //             if(node->left != nullptr) {
    //                 nodeQue.push(node->left);
    //             }
    //             if(node->right != nullptr) {
    //                 nodeQue.push(node->right);
    //             }
    //         }
    //         ++level;
    //     }
    //     return level;
    // }

    // 递归
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int level) {
        if(root == nullptr) {
            return INT_MAX;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return level + 1;
        }
        int leftLevel = dfs(root->left, level + 1);
        int rightLevel = dfs(root->right, level + 1);
        return min(leftLevel, rightLevel);
    }
};
// @lc code=end

