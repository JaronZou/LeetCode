/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseNNode(ListNode *head, int n) {
        ListNode *pre, *cur, *next, *result = head->next;
        pre = head->next;
        cur = pre->next;
        // 这里已经反转了一个结点了，因此--n
        pre->next = nullptr;
        --n;
        // 反转剩余的结点
        while(n > 0) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            --n;
        }
        // 反转后接上链表
        // 一定注意：这里不是cur，而是pre，只要模拟一遍即可明白
        head->next = pre;
        return result;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == nullptr || head->next == nullptr) {
            return head;
        }
        // 新键一个辅助头结点。
        ListNode *slow = new ListNode, *fast = head, *p;
        slow->next = head;
        head = slow;
        // fast指针向前走k步
        int count = k;
        while(count > 0 && fast != nullptr) {
            fast = fast->next;
            --count;
        }
        // 反转链表
        while(1) {
            // count == 0，说明fast向前走了k步，
            // 说明剩余的结点数量大于等于k，也就能进行反转
            if(count == 0) {
                p = reverseNNode(slow, k);
                p->next = fast;
                slow = p;
            }
            // count != 0，说明fast没有走k步，说明剩下的节点数量不足k个
            // 不能反转，跳出循环。
            else {
                break;
            }
            // fast继续向前走k步。
            count = k;
            while(count > 0 && fast != nullptr) {
                fast = fast->next;
                --count;
            }
        }
        // 删除辅助作用的头结点
        slow = head;
        head = head->next;
        delete slow;
        return head;
    }
};
// @lc code=end

