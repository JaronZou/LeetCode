/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    /* 递归实现 */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return process(l1, l2, false);
    }

    ListNode* process(ListNode *l1, ListNode *l2, bool isCarry) {
        if((l1 == nullptr) && (l2 == nullptr)) {
            if(isCarry) {
                return (new ListNode(1, nullptr));
            }
            return nullptr;
        }
        int sum = isCarry;
        sum += (l1 ? l1->val : 0);
        sum += (l2 ? l2->val : 0);
        l1 = (l1 ? l1->next : l1);
        l2 = (l2 ? l2->next : l2);
        ListNode *result = new ListNode(sum % 10, nullptr);
        result->next = process(l1, l2, sum / 10);
        return result;
    }

    // /* 非递归实现 */
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     bool isCarry = false;
    //     ListNode *head = new ListNode(0, nullptr), *cur = head;
    //     while(l1 || l2 || isCarry) {
    //         int sum = isCarry;
    //         sum += (l1 ? l1->val : 0);
    //         sum += (l2 ? l2->val : 0);
    //         /* 链接下一个结点 */
    //         cur->next = new ListNode(sum % 10, nullptr);
    //         cur = cur->next;
    //         l1 = (l1 ? l1->next : l1);
    //         l2 = (l2 ? l2->next : l2);
    //         isCarry = sum / 10;
    //     }
    //     cur = head->next;
    //     delete head;
    //     return cur;
    // }
};
// @lc code=end

