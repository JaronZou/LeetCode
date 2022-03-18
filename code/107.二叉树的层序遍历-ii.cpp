/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    // 层序遍历，然后反转即可
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     if(root == nullptr) {
    //         return {};
    //     }
    //     int curLevel = -1;
    //     TreeNode *curNode = nullptr;
    //     TreeNode *curLevelEnd = nullptr;
    //     TreeNode *nextLevelEnd = root;
    //     queue<TreeNode*> nodeQue;
    //     nodeQue.push(root);
    //     while(!nodeQue.empty()) {
    //         curNode = nodeQue.front();
    //         nodeQue.pop();
    //         // 当前来到新的一层
    //         if(curLevelEnd == nullptr) {
    //             result.emplace_back();
    //             curLevelEnd = nextLevelEnd;
    //             ++curLevel;
    //         }
    //         result[curLevel].push_back(curNode->val);
    //         // 当前来到当前行的最后一个结点
    //         if(curNode == curLevelEnd) {
    //             curLevelEnd = nullptr;
    //         }
    //         // 左右孩子入队
    //         if(curNode->left != nullptr) {
    //             nodeQue.push(curNode->left);
    //             nextLevelEnd = curNode->left;
    //         }
    //         if(curNode->right != nullptr) {
    //             nodeQue.push(curNode->right);
    //             nextLevelEnd = curNode->right;
    //         }
    //     }
    //     return {result.crbegin(), result.crend()};
    // }

    // 每遍历到新的一层时，队列的大小就是该层的结点数量
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> nodeQue;
        vector<vector<int>> result;
        if(root != nullptr) {
            nodeQue.push(root);
        }
        TreeNode *curNode;
        int curLevelNums = 0;
        while(!nodeQue.empty()) {
            result.emplace_back();
            curLevelNums = nodeQue.size();
            for(int i = 0; i < curLevelNums; ++i) {
                curNode = nodeQue.front();
                nodeQue.pop();
                result.back().push_back(curNode->val);
                if(curNode->left != nullptr) {
                    nodeQue.push(curNode->left);
                }
                if(curNode->right != nullptr) {
                    nodeQue.push(curNode->right);
                }
            }
        }
        return {result.crbegin(), result.crend()};
    }

private:
    vector<vector<int>> result;
};
// @lc code=end

