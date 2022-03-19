/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *newList = head;
        ListNode *remains = new ListNode;
        ListNode *newListNode = head, *remainNode = remains;
        ListNode *curNode = head->next;
        while(curNode != nullptr) {
            if(curNode->val == newListNode->val) {
                remainNode->next = curNode;
                remainNode = curNode;
            }
            else {
                newListNode->next = curNode;
                newListNode = curNode;
            }
            curNode = curNode->next;
        }
        newListNode->next = nullptr;
        remainNode->next = nullptr;
        // 删除结点
        while(remains != nullptr) {
            remainNode = remains->next;
            delete remains;
            remains = remainNode;
        }
        return newList;
    }
};
// @lc code=end

