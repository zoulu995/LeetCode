/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        if (!k) return head;
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;
        
        k %= n;
        auto a = head, b = head;
        n = k;
        while (n --) b = b->next;
        while (b->next) {
            a = a->next;
            b = b->next;
        }
        
        b->next = head;
        head = a->next;
        a->next = NULL;

        return head;

    }
};
// @lc code=end

