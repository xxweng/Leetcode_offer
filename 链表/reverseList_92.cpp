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
        ListNode* dummyNode = new ListNode(-1);
        ListNode* pre = dummyNode;
        dummyNode->next = head;

        for(int i = 0; i < m - 1; i++)
        {
            pre = pre->next;
        }
        //cur为翻转部分前的那个节点。
        ListNode* cur = pre->next;
        for(int i = m; i < n; i++)
        {
            ListNode* last = cur->next; //要翻转部分的原始第一个节点
            cur->next = last->next; //把要fan
            last->next = pre->next; //
            pre->next = last; //
        }
        
        return dummyNode->next;
    }
};
// @lc code=end

