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
        ListNode* cur = pre->next;
        for(int i = m; i < n; i++)
        {
            ListNode* last = cur->next;
            cur->next = last->next;
            last->next = pre->next;
            pre->next = last;
        }
        
        return dummyNode->next;
    }
};
// @lc code=end

