/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    // 反转以head->next、和head->next->next，并将反转的结果挂到head后
    void reverseTwoNode(ListNode *head) {
        ListNode *p = head->next, *q = head->next->next;
        q->next = p;
        p->next = nullptr;
        head->next = q;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = new ListNode;
        slow->next = head;
        head = slow;
        ListNode *fast = head, *cur = nullptr;
        fast = fast->next->next->next;
        while(fast != nullptr && fast->next != nullptr) {
            reverseTwoNode(slow);
            slow = slow->next->next;
            slow->next = fast;
            fast = fast->next->next;
        }
        reverseTwoNode(slow);
        slow = slow->next->next;
        slow->next = fast;
        // 删除作为辅助的头结点
        slow = head;
        head = head->next;
        delete slow;
        return head;
    }
};
// @lc code=end

