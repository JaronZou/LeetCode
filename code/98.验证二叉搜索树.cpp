/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // long long preVal = LLONG_MIN;

    // bool isValidBST(TreeNode* root) {
    //     if(root == nullptr) {
    //         return true;
    //     }
    //     // 左子树必须为BST
    //     if(!isValidBST(root->left)) {
    //         return false;
    //     }
    //     // 当前结点必须满足当前结点大于前一个结点值
    //     if(preVal >= root->val) {
    //         return false;
    //     }
    //     preVal = root->val;
    //     // 右子树也必须为BST
    //     return isValidBST(root->right);
    // }

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root;
        long long preVal = LLONG_MIN;
        while(cur != nullptr || !nodeStack.empty()) {
            if(cur != nullptr) {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else {
                cur = nodeStack.top();
                nodeStack.pop();
                if(preVal >= cur->val) {
                    return false;
                }
                preVal = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
};
// @lc code=end

