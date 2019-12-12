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
         if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        if(slow == fast->next->next)
        {
            return slow;
        }

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                fast = head;
                while(slow != NULL)
                {
                    fast = fast->next;
                    slow = slow->next;
                    if(slow == fast)
                    {
                        return slow;
                    }
                }
            }
        }
        return NULL;
    }
};
// @lc code=end

