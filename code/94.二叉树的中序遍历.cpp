/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // // 最简单的方法：递归
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> arr;
    //     process(root, arr);
    //     return arr;
    // }

    // void process(TreeNode* root, vector<int> &arr) {
    //     if(root == nullptr) {
    //         return;
    //     }
    //     process(root->left, arr);
    //     arr.push_back(root->val);
    //     process(root->right, arr);
    // }

    // 非递归
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root;
        while(cur != nullptr || !nodeStack.empty()) {
            if(cur != nullptr) {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else {
                cur = nodeStack.top();
                nodeStack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end

