/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     if(root == nullptr) {
    //         return {};
    //     }
    //     vector<vector<int>> paths;
    //     vector<int> path;
    //     process(paths, path, root, targetSum);
    //     return paths;
    // }

    // void process(vector<vector<int>> &paths, vector<int> &path, TreeNode *root, int targetSum) {
    //     path.push_back(root->val);
    //     // base case
    //     if(root->left == nullptr && root->right == nullptr) {
    //         if(root->val == targetSum) {
    //             paths.push_back(path);
    //         }
    //         path.pop_back();
    //         return;
    //     }
    //     if(root->left != nullptr) {
    //         process(paths, path, root->left, targetSum - root->val);
    //     }
    //     if(root->right != nullptr) {
    //         process(paths, path, root->right, targetSum - root->val);
    //     }
    //     path.pop_back();
    // }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> paths;
        unordered_map<TreeNode*, TreeNode*> fatherMap;
        fatherMap[root] = root;
        // nodeQue和sumQue分别用来遍历结点和存储路径值之和。
        queue<TreeNode*> nodeQue;
        queue<int> sumQue;
        nodeQue.push(root);
        sumQue.push(root->val);
        while(!nodeQue.empty()) {
            TreeNode *curNode = nodeQue.front();
            nodeQue.pop();
            int curPathSum = sumQue.front();
            sumQue.pop();
            // 当前结点为叶子结点且路径和为targetSum
            if(curNode->left == nullptr &&
                curNode->right == nullptr &&
                curPathSum == targetSum) {
                vector<int> tmpPath;
                TreeNode *tmpNode = curNode;
                while(tmpNode != fatherMap[tmpNode]) {
                    tmpPath.push_back(tmpNode->val);
                    tmpNode = fatherMap[tmpNode];
                }
                tmpPath.push_back(root->val);
                paths.emplace_back(tmpPath.rbegin(), tmpPath.rend());
            }
            // 左孩子结点不为空
            if(curNode->left != nullptr) {
                nodeQue.push(curNode->left);
                sumQue.push(curNode->left->val + curPathSum);
                fatherMap[curNode->left] = curNode;
            }
            // 右孩子结点不为空
            if(curNode->right != nullptr) {
                nodeQue.push(curNode->right);
                sumQue.push(curNode->right->val + curPathSum);
                fatherMap[curNode->right] = curNode;
            }
        }
        return paths;
    }
};
// @lc code=end

