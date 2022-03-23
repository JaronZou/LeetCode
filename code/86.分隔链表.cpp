/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *more = new ListNode;
        ListNode *m = more;
        ListNode *less = new ListNode;
        ListNode *l = less;
        while(head != nullptr) {
            if(head->val < x) {
                l->next = head;
                head = head->next;
                l = l->next;
            }
            else {
                m->next = head;
                head = head->next;
                m = m->next;
            }
        }
        m->next = nullptr;
        l->next = more->next;
        l = less->next;
        delete less;
        delete more;
        return l;
    }
};
// @lc code=end

