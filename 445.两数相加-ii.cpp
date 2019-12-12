/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (52.17%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 18.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummyNode = new ListNode(-1);
       ListNode* temp = NULL;

       stack<int> stack1;
       stack<int> stack2;
       while(l1 != NULL)
       {
           stack1.push(l1->val);
           l1 = l1->next;
       }
       while(l2 != NULL)
       {
           stack2.push(l2->val);
           l2 = l2->next;
       }
       int carry = 0;
       int val1, val2, sum;
       while(!stack1.empty() || !stack2.empty() || carry)
       {
           if(stack1.empty())
           {
               val1 = 0;
           }
           else
           {
               val1 = stack1.top();
               stack1.pop();
           }
           

           if(stack2.empty())
           {
               val2 = 0;
           }
           else
           {
               val2 = stack2.top();
               stack2.pop();
           }
           
           sum = val1 + val2 + carry;

           temp = new ListNode(sum%10);
           temp->next = dummyNode->next;
           dummyNode->next = temp;

           carry = sum/10;
       }
       return dummyNode->next;
    }
};
// @lc code=end

