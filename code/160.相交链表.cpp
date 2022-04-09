/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        ListNode *nodeA = headA, *nodeB = headB;
        while(nodeA != nullptr) {
            ++sizeA;
            nodeA = nodeA->next;
        }
        while(nodeB != nullptr) {
            ++sizeB;
            nodeB = nodeB->next;
        }
        nodeA = sizeA > sizeB ? headA : headB;
        nodeB = nodeA == headA ? headB : headA;
        int sub = sizeA - sizeB;
        sub = sub < 0 ? -sub : sub;
        while(sub > 0) {
            nodeA = nodeA->next;
            --sub;
        }
        while(nodeA != nodeB && nodeA != nullptr && nodeB != nullptr) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nodeA == nullptr || nodeB == nullptr ? nullptr : 
               (nodeA == nodeB ? nodeA : nullptr);
    }
};
// @lc code=end

