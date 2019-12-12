/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        //声明链表的头结点
        ListNode odd_node(0);
        ListNode even_node(0);
        //头结点的地址
        ListNode* odd_head = &odd_node;
        ListNode* even_head = &even_node;
        int count = 1;
        while(head)
        {
            if(count % 2 != 0)
            {
                odd_head->next = head;
                odd_head = head;
                
            }
            else
            {
                even_head->next = head;
                even_head = head;
            }
            head = head->next;
            count++;
        }
        even_head->next = NULL;
        odd_head->next = even_node.next;
        return odd_node.next;
        

    }
};
// @lc code=end

