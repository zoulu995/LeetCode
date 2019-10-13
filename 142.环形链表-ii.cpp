/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return head;
        auto fast = head, slow = head;
        while (slow)
        {
            /* code */
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            else return NULL;
            if (fast == NULL)
            {
                /* code */
                return NULL;
            }
            
            if (fast == slow) {
                fast = head;
                while (fast != slow) fast = fast->next, slow = slow->next;
                return fast;
            }
        }

        return NULL;
        
    }
};
// @lc code=end

