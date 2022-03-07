/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct NodeCompare {
        bool operator()(ListNode *n1, ListNode *n2) {
            return n1->val > n2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        // 按val维护的小根堆
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> nodeHeap;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != nullptr) {
                nodeHeap.push(lists[i]);
            }
        }
        // 构建的新链表的头指针
        ListNode *head = new ListNode;
        ListNode *cur = head;
        // 每次从堆中弹出一个最小的结点，再将该结点的后续结点加入堆中。
        while(!nodeHeap.empty()) {
            cur->next = nodeHeap.top();
            nodeHeap.pop();
            cur = cur->next;
            // 弹出结点的后继结点不为空，将后继结点加入堆中
            if(cur->next != nullptr) {
                nodeHeap.push(cur->next);
            }
            cur->next = nullptr;
        }
        // 删除前面作为辅助用途的头结点
        cur = head;
        head = head->next;
        delete cur;
        return head;
    }
};
// @lc code=end

