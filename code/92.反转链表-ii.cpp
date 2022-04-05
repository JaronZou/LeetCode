/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *newHead = new ListNode;
        newHead->next = head;
        head = newHead;
        ListNode *preNode = nullptr;
        int i = 0;
        // 找到left结点和left结点之前的一个结点
        while(i < left) {
            preNode = head;
            head = head->next;
            ++i;
        }
        // 记录反转部分反转后的最后一个结点
        ListNode *p = preNode->next;
        head = head->next;
        ++i;
        while(i <= right) {
            ListNode *next = head->next;
            // 做头插
            head->next = preNode->next;
            preNode->next = head;
            head = next;
            ++i;
        }
        p->next = head;
        head = newHead->next;
        delete newHead;
        return head;
    }
};
// @lc code=end

