/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    // 递归实现
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(p == nullptr && q == nullptr) {
    //         return true;
    //     }
    //     else if(p == nullptr || q == nullptr){
    //         return false;
    //     }
    //     else if(p->val != q->val) {
    //         return false;
    //     }
    //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // }

    // 当p和q中一个为空一个不为空时，返回true，否则返回false。
    // bool isOneEmpty(TreeNode* p, TreeNode* q) {
    //     return (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr);
    // }

    // 非递归先序遍历实现
    // bool isSameTree(TreeNode* p, TreeNode* q) { 
    //     if(p == nullptr && q == nullptr) {
    //         return true;
    //     }
    //     stack<TreeNode*> nodeStack;
    //     TreeNode *cur1 = p, *cur2 = q;
    //     nodeStack.push(cur1);
    //     nodeStack.push(cur2);
    //     while(!nodeStack.empty()) {
    //         cur2 = nodeStack.top();
    //         nodeStack.pop();
    //         cur1 = nodeStack.top();
    //         nodeStack.pop();
    //         // 两个结点一个为空，一个不为空
    //         if(isOneEmpty(cur1, cur2)) {
    //             return false;
    //         }
    //         // 两个结点都不为空，但两个结点的值不相等或两个结点的子结点一个为空，一个不为空
    //         else if(cur1 != nullptr){
    //             if(cur1->val != cur2->val || 
    //                isOneEmpty(cur1->left, cur2->left) ||
    //                isOneEmpty(cur1->right, cur2->right)) {
    //                 return false;
    //             }
    //         }
    //         // 现在两个结点的孩子结点要么都为空，要么都不为空
    //         if(cur1->left != nullptr) {
    //             nodeStack.push(cur1->left);
    //             nodeStack.push(cur2->left);
    //         }
    //         if(cur1->right != nullptr) {
    //             nodeStack.push(cur1->right);
    //             nodeStack.push(cur2->right);
    //         }
    //     }
    //     return true;
    // }

    // 非递归中序遍历实现
    // bool isSameTree(TreeNode* p, TreeNode* q) { 
    //     if(p == nullptr && q == nullptr) {
    //         return true;
    //     }
    //     stack<TreeNode*> nodeStack;
    //     TreeNode *cur1 = p, *cur2 = q;
    //     while(cur1 != nullptr || cur2 != nullptr || !nodeStack.empty()) {
    //         // cur1和cur2都不为空
    //         if(cur1 != nullptr && cur2 != nullptr) {
    //             // 弹出时的顺序应该相反
    //             nodeStack.push(cur1);
    //             nodeStack.push(cur2);
    //             cur1 = cur1->left;
    //             cur2 = cur2->left;
    //         }
    //         // cur1和cur2中有一个为空，而另一个不为空
    //         else if(cur1 != nullptr || cur2 != nullptr) {
    //             return false;
    //         }
    //         // cur1和cur2都为空
    //         else {
    //             cur2 = nodeStack.top();
    //             nodeStack.pop();
    //             cur1 = nodeStack.top();
    //             nodeStack.pop();
    //             if(cur1->val != cur2->val) {
    //                 return false;
    //             }
    //             cur1 = cur1->right;
    //             cur2 = cur2->right;
    //         }
    //     }
    //     return true;
    // }

    // 当p和q中一个为空一个不为空时，返回true，否则返回false。
    bool isOneEmpty(TreeNode* p, TreeNode* q) {
        return (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr);
    }

    // 非递归后序遍历实现，只是没有使用收集栈将结点收集(所以严格来说应该是反后序遍历)
    bool isSameTree(TreeNode* p, TreeNode* q) { 
        if(p == nullptr && q == nullptr) {
            return true;
        }
        stack<TreeNode*> nodeStack;
        TreeNode *cur1 = p, *cur2 = q;
        nodeStack.push(cur1);
        nodeStack.push(cur2);
        while(!nodeStack.empty()) {
            cur1 = nodeStack.top();
            nodeStack.pop();
            cur2 = nodeStack.top();
            nodeStack.pop();
            // 两个结点有一个为空、另一个不为空
            if(isOneEmpty(cur1, cur2)) {
                return false;
            }
            // 两个结点都不为空
            else if(cur1 != nullptr) {
                if(cur1->val != cur2->val || 
                   isOneEmpty(cur1->left, cur2->left) ||
                   isOneEmpty(cur1->right, cur2->right)) {
                    return false;
                }
                if(cur1->left != nullptr) {
                    nodeStack.push(cur1->left);
                    nodeStack.push(cur2->left);
                }
                if(cur2->right != nullptr) {
                    nodeStack.push(cur1->right);
                    nodeStack.push(cur2->right);
                }
            }
        }
        return true;
    }
};
// @lc code=end

