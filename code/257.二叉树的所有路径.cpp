/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
class Solution
{
public:
    // 利用父结点表保存所有路径，当遍历到叶子结点时，生成路径并保存
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     if(root == nullptr) {
    //         return {};
    //     }
    //     vector<string> res;
    //     unordered_map<TreeNode*, TreeNode*> fatherMap;
    //     queue<TreeNode*> nodeQue;
    //     stack<TreeNode*> nodeStack;
    //     fatherMap[root] = root;
    //     nodeQue.push(root);
    //     while(!nodeQue.empty()) {
    //         TreeNode *cur = nodeQue.front();
    //         nodeQue.pop();
    //         // 当前结点为叶子结点
    //         if(cur->left == nullptr && cur->right == nullptr) {
    //             TreeNode *tmpNode = cur;
    //             while(tmpNode != fatherMap[tmpNode]) {
    //                 nodeStack.push(tmpNode);
    //                 tmpNode = fatherMap[tmpNode];
    //             }
    //             string path = to_string(root->val);
    //             while(!nodeStack.empty()) {
    //                 path.append("->");
    //                 tmpNode = nodeStack.top();
    //                 nodeStack.pop();
    //                 path.append(to_string(tmpNode->val));
    //             }
    //             res.push_back(path);
    //         }
    //         if(cur->left != nullptr) {
    //             fatherMap[cur->left] = cur;
    //             nodeQue.push(cur->left);
    //         }
    //         if(cur->right != nullptr) {
    //             fatherMap[cur->right] = cur;
    //             nodeQue.push(cur->right);
    //         }
    //     }
    //     return res;
    // }

    // 深搜(dfs)
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<string> res;
        string path;
        dfs(root, res, path);
        return res;
    }

    // 深搜(deepth search first)
    void dfs(TreeNode *root, vector<string> &res, string path) {
        if (root->left == nullptr && root->right == nullptr) {
            path.append(to_string(root->val));
            res.push_back(path);
            return;
        }
        path.append(to_string(root->val));
        path.append("->");
        if (root->left != nullptr) {
            dfs(root->left, res, path);
        }
        if (root->right != nullptr) {
            dfs(root->right, res, path);
        }
    }
};
// @lc code=end
