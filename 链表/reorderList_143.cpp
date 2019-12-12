/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (53.15%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 23.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        ListNode* cur = head;
        stack<ListNode*> reStack;
        int len = 0;
        while(cur != NULL)
        {
            reStack.push(cur);
            len++;
            cur = cur->next;
        }
        cur = head;
        for(int i = 0; i < len/2; i++)
        {
            ListNode* temp = cur->next;
            cur->next = reStack.top();
            reStack.pop();
            cur->next->next = temp;
            cur = temp;
        }
        cur->next = NULL;
        return;
    }
};
// @lc code=end

