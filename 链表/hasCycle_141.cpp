/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) 
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {     
                return true;
                /*     找第一个入口节点
                fast = head;
                while(slow != NULL)
                {
                    fast = fast->next;
                    slow = slow->next;
                    if(fast == slow)
                    {
                        return true;
                    }
                }
                */
               
                
            }
           
        }
        return false;

    }
};
// @lc code=end

