/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* findAllSameNode(ListNode* node) {
        ListNode *curNode = node, *preNode = node;
        while(curNode != nullptr) {
            if(curNode->val == node->val) {
                preNode = curNode;
                curNode = curNode->next;
            }
            else {
                break;
            }
        }
        return preNode;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode;
        newHead->next = head;
        ListNode *curNode = head, *preNode = newHead;
        while(curNode != nullptr) {
            ListNode *nextSameNode = findAllSameNode(curNode);
            if(nextSameNode != curNode) {
                preNode->next = nextSameNode->next;
                nextSameNode->next = nullptr;
                while(curNode != nullptr) {
                    nextSameNode = curNode->next;
                    delete curNode;
                    curNode = nextSameNode;
                }
                curNode = preNode->next;
            }
            else {
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};
// @lc code=end

