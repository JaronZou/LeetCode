/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = nullptr;
        // 题目说明node->next不为空
        while(node->next->next != nullptr) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        delete node->next;
        node->next = nullptr;
    }
};
// @lc code=end

