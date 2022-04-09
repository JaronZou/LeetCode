/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = new ListNode;
        ListNode *pre = newHead;
        newHead->next = head;
        while(head != nullptr) {
            if(head->val == val) {
                pre->next = head->next;
                delete head;
                head = pre->next;
            }
            else {
                pre = head;
                head = head->next;
            }
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};
// @lc code=end

