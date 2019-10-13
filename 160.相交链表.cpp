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
        auto p = headA, q = headB;
        while (p != q) { 
            if (p) p = p->next; //不能判断 p->next是否存在
            else p = headB;     //这样他们始终取不到NULL的值

            if (q) q = q->next;
            else q = headA;
        }

        return p;
    }
};
// @lc code=end

