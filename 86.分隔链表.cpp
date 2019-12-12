/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        //声明两个临时结点。这两个的作用是不变的头，便于后面连接两个分开的链表以及返回链表头
        ListNode small_node(0);
        ListNode big_node(0);
        //创建两个指向这两个结点的指针
        ListNode* small_head = &small_node;
        ListNode* big_head = &big_node;
 
        while(head != NULL)
        {
            if(head->val < x)
            {
                small_head->next = head;
                small_head = head;
            }
            else
            {
                big_head->next = head;
                big_head = head;
            }
            head = head->next;
        }
        big_head->next = NULL;
        small_head->next = big_node.next;
        return small_node.next;
    }
};
// @lc code=end

