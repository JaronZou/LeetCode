/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    // 反转一半链表，判断是否与另一半相等
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) {
            return true;
        }
        // 计算链表长度
        int listSize = 0;
        ListNode *node = head;
        while(node != nullptr) {
            node = node->next;
            ++listSize;
        }
        // 拿到链表长度的一半，如果是链表长度为奇数，就加一
        int halfSize = listSize / 2;
        halfSize = listSize % 2 == 1 ? halfSize + 1 : halfSize;
        // 先走一半的长度
        node = head;
        while(halfSize > 0) {
            node = node->next;
            --halfSize;
        }
        // 反转一半链表
        node = reverseList(node);
        // 比较两半链表是否相等
        while(node != nullptr) {
            if(node->val != head->val) {
                return false;
            }
            node = node->next;
            head = head->next;
        }
        return true;
    }
    
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = new ListNode;
        newHead->next = head;
        ListNode *node = head->next, *next = nullptr;
        head->next = nullptr;
        while(node != nullptr) {
            next = node->next;
            node->next = newHead->next;
            newHead->next = node;
            node = next;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }   
};
// @lc code=end

