/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root == nullptr) {
    //         return false;
    //     }
    //     // base case
    //     // 找到了根节点，返回当前的和是否为targetSum
    //     if(root->left == nullptr && root->right == nullptr) {
    //         return root->val == targetSum;
    //     }  
    //     // 搜寻左子树和右子树
    //     bool flag1 = hasPathSum(root->left, targetSum - root->val);
    //     bool flag2 = hasPathSum(root->right, targetSum - root->val);
    //     // 只要有一个路径和为targetSum，那么就返回真
    //     return flag1 || flag2;
    // }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        // 用来遍历二叉树
        queue<TreeNode*> nodeQue;
        // 记录根节点到当前结点的路径和
        queue<int> sumQue;
        nodeQue.push(root);
        sumQue.push(root->val);
        while(!sumQue.empty()) {
            // 弹出队头结点和头结点到该结点的路径和
            TreeNode *cur = nodeQue.front();
            nodeQue.pop();
            int curSum = sumQue.front();
            sumQue.pop();
            // 如果没有左右孩子并且当前路径和即为targetSum，那么直接返回true。
            if(cur->left == nullptr && 
               cur->right == nullptr &&
               curSum == targetSum) {
                return true;
            }
            // 左右孩子结点入队
            if(cur->left != nullptr) {
                nodeQue.push(cur->left);
                sumQue.push(cur->left->val + curSum);
            }
            if(cur->right != nullptr) {
                nodeQue.push(cur->right);
                sumQue.push(cur->right->val + curSum);
            }
        }
        return false;
    }
};
// @lc code=end

