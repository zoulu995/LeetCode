/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
        {
            /* code */
            return NULL;
        }
        
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto a = dummy, b = dummy;
        int k = n;
        while (k --) a = a->next;
        while (a->next) {
            a = a->next;
            b = b->next;
        }
        b->next = b->next->next;

        return dummy->next;
    }
};
// @lc code=end

