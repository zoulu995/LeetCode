/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto a = dummy->next, b = dummy->next->next;
        while (b && a) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }

        dummy->next->next = NULL;
        return a;

    }
};
// @lc code=end

