fou/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int count = 0;
    //     ListNode *cur = head;
    //     while(cur != nullptr) {
    //         ++count;
    //         cur = cur->next;
    //     }
    //     if(count == n) {
    //         cur = head;
    //         head = head->next;
    //         delete cur;
    //         return head;
    //     }
    //     else {
    //         cur = head;
    //         count = count - n;
    //         ListNode *pre, *next;
    //         while(count != 0) {
    //             --count;
    //             pre = cur;
    //             cur = cur->next;
    //         }
    //         next = cur->next;
    //         pre->next = next;
    //         delete cur;
    //     }
    //     return head;
    // }

    // 双指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while(n != 0) {
            --n;
            fast = fast->next;
        }
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // fast == nullptr，那么要删除的就是头结点
        if(fast == nullptr) {
            head = head->next;
            delete slow;
        }
        // 否则，删除的就是中间的某个结点
        else {
            ListNode *cur = slow->next;
            slow->next = cur->next;
            delete cur;
        }
        return head;
    }
};
// @lc code=end

