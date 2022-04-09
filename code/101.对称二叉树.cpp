/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // 左子树 头->左->右，右子树 头->右->左
    bool isSymmetric(TreeNode* root) {
        dfs(root->left, root->right);
        return ans;
    }

    void dfs(TreeNode *left, TreeNode *right) {
        if(!ans) {
            return;
        }
        if(left != nullptr && right != nullptr) {
            ans &= (left->val == right->val);
            dfs(left->left, right->right);
            dfs(left->right, right->left);
        }
        else if(!(left == nullptr && right == nullptr)){
            ans &= false;
        }
    }

private:
    bool ans = true;
};
// @lc code=end

