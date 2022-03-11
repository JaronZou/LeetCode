/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // void process(TreeNode *root, vector<int> &res) {
    //     if(root == nullptr) {
    //         return;
    //     }
    //     res.push_back(root->val);
    //     if(root->left != nullptr) {
    //         process(root->left, res);
    //     }
    //     if(root->right != nullptr) {
    //         process(root->right, res);
    //     }
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     process(root, res);
    //     return res;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        stack<TreeNode*> nStack;
        vector<int> res;
        nStack.push(root);
        while(!nStack.empty()) {
            TreeNode *cur = nStack.top();
            nStack.pop();
            res.push_back(cur->val);
            if(cur->right != nullptr) {
                nStack.push(cur->right);
            }
            if(cur->left != nullptr) {
                nStack.push(cur->left);
            }
        }
        return res;
    }
};
// @lc code=end

