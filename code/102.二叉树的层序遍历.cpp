/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if(root == nullptr) {
    //         return {};
    //     }
    //     vector<vector<int>> result;
    //     vector<int> curLevelVals;
    //     queue<TreeNode*> nodeQue;
    //     nodeQue.push(root);
    //     // curLevelEnd和nextLevelEnd分别表示当前层的最后一个结点和下一层的最后一个结点
    //     TreeNode *cur, *curLevelEnd = root, *nextLevelEnd = nullptr;
    //     while(!nodeQue.empty()) {
    //         // curLevelEnd 等于 nullptr，说明来到了新一层。
    //         if(curLevelEnd == nullptr) {
    //             curLevelEnd = nextLevelEnd;
    //         }
    //         cur = nodeQue.front();
    //         nodeQue.pop();
    //         curLevelVals.push_back(cur->val);
    //         // 当前来到了当前层的最后一个结点，结算该层的结点
    //         if(cur == curLevelEnd) {
    //             result.push_back(curLevelVals);
    //             curLevelVals = vector<int>();
    //             curLevelEnd = nullptr;
    //         }
    //         // 左孩子、右孩子入队(如果有的话)
    //         if(cur->left != nullptr) {
    //             nodeQue.push(cur->left);
    //             nextLevelEnd = cur->left;
    //         }
    //         if(cur->right != nullptr) {
    //             nodeQue.push(cur->right);
    //             nextLevelEnd = cur->right;
    //         }
    //     }
    //     return result;
    // }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        // curLevel表示当前所在层级
        int curLevel = 0;
        while(!q.empty()) {
            // 由于每到一层的开头，上一层的结点就全部被弹出了，
            // 因此我们可以用q.size()表示当前层有多少个结点
            int curLevelSize = q.size();
            TreeNode *cur;
            result.push_back(vector<int>());
            // 我们只弹出当前层的结点，下一层的结点在下一次循环处理
            for(int i = 0; i < curLevelSize; ++i) {
                cur = q.front();
                q.pop();
                // 当前层的结点的值
                result[curLevel].push_back(cur->val);
                // 左右孩子入队
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            ++curLevel;
        }
        return result;
    }
};
// @lc code=end

