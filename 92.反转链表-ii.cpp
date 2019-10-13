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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        
        auto a = dummy, c = dummy, d = dummy;
        for (int i = 0; i < m - 1; i ++) a = a->next;
        for (int i = 0; i < n + 1; i ++) c = c->next;
        for (int i = 0; i < n; i ++) d = d->next;

        for (auto p = a->next, q = a->next->next; q != c; ) {
            auto o = q->next;
            q->next = p;
            p = q, q = o;
        }

        a->next->next = c;
        a->next = d;

        return dummy->next;
    }
};
// @lc code=end

