/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    //     if(root->left != nullptr) {
    //         process(root->left, res);
    //     }
    //     if(root->right != nullptr) {
    //         process(root->right, res);
    //     }
    //     res.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     process(root, res);
    //     return res;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        stack<TreeNode*> tmpNStack;
        vector<int> res;
        tmpNStack.push(root);
        while(!tmpNStack.empty()) {
            TreeNode *cur = tmpNStack.top();
            tmpNStack.pop();
            res.push_back(cur->val);
            if(cur->left != nullptr) {
                tmpNStack.push(cur->left);
            }
            if(cur->right != nullptr) {
                tmpNStack.push(cur->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

