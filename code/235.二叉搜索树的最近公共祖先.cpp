/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     return process(root, p, q);
    // }

    // TreeNode* process(TreeNode *root, TreeNode *p, TreeNode *q) {
    //     if(root == nullptr || root == p || root == q) {
    //         return root;
    //     }
    //     TreeNode *left = process(root->left, p, q);
    //     TreeNode *right = process(root->right, p, q);
    //     if(left != nullptr && right != nullptr) {
    //         return root;
    //     }
    //     return left != nullptr ? left : right;
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(root == p || root == q) {
    //         return root;
    //     }
    //     unordered_set<TreeNode*> nodeSet;
    //     // 先找p
    //     TreeNode *cur = root;
    //     nodeSet.insert(cur);
    //     while(cur != p) {
    //         if(p->val < cur->val) {
    //             cur = cur->left;
    //         }
    //         else {
    //             cur = cur->right;
    //         }
    //         nodeSet.insert(cur);
    //     }
    //     // 寻找q结点，最后一个查找到在nodeSet中的结点，就是我们要找的结点
    //     TreeNode *pre = root;
    //     cur = root;
    //     while(cur != q) {
    //         if(q->val < cur->val) {
    //             cur = cur->left;
    //         }
    //         else {
    //             cur = cur->right;
    //         }
    //         if(nodeSet.count(cur) == 0) {
    //             return pre;
    //         }
    //         pre = cur;
    //     }
    //     return pre;
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     while(root != p && root != q) {
    //         if(p->val < root->val && q->val < root->val) {
    //             root = root->left;
    //         }
    //         else if(p->val > root->val && q->val > root->val) {
    //             root = root->right;
    //         }
    //         else {
    //             return root;
    //         }
    //     }
    //     return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return root;
        }
    }
};
// @lc code=end

