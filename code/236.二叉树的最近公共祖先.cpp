/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    // void TraverseNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &fatherMap) {
    //     fatherMap[root] = root;
    //     queue<TreeNode*> nodeQue;
    //     nodeQue.push(root);
    //     while(!nodeQue.empty()) {
    //         TreeNode *cur = nodeQue.front();
    //         nodeQue.pop();
    //         if(cur->left != nullptr) {
    //             fatherMap[cur->left] = cur;
    //             nodeQue.push(cur->left);
    //         }
    //         if(cur->right != nullptr) {
    //             fatherMap[cur->right] = cur;
    //             nodeQue.push(cur->right);
    //         }
    //     }
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     // 构造父结点表
    //     unordered_map<TreeNode*, TreeNode*> fatherMap;
    //     unordered_set<TreeNode*> nset;
    //     TraverseNode(root, fatherMap);
    //     while(fatherMap[p] != p) {
    //         nset.insert(p);
    //         p = fatherMap[p];
    //     }
    //     nset.insert(root);

    //     while(fatherMap[q] != q) {
    //         if(nset.count(q) != 0) {
    //             return q;
    //         }
    //         q = fatherMap[q];
    //     }
    //     return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        // 向左右子树要信息
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 左右子树上各有p、q中的一个结点，那么找到了它们的最低公共祖先
        if(left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};
// @lc code=end

