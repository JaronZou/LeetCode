/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max;
    }

    int dfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftMax = std::max(0, dfs(root->left));
        int rightMax = std::max(0, dfs(root->right));
        max = std::max(max, leftMax + rightMax + root->val);
        return root->val + std::max(leftMax, rightMax);
    }

private:
    int max = INT_MIN;
};
// @lc code=end

