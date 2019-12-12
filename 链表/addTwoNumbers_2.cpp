/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.13%)
 * Likes:    3526
 * Dislikes: 0
 * Total Accepted:    274.2K
 * Total Submissions: 758.8K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;S
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len_1 = 1;
        int len_2 = 1;

        ListNode* list_1 = l1;
        ListNode* list_2 = l2;
        while(list_1->next != NULL)
        {
            len_1++;
            list_1 = list_1->next;
        }

        while(list_2->next != NULL)
        {
            len_2++;
            list_2 = list_2->next;
        } 

        int diff = len_1 - len_2;
        //l2比l1短
        while(diff > 0)
        {
            diff--;
            //新创建一个结点
            list_2->next = new ListNode(0);
            list_2 = list_2->next;
        }
        //l1比l2短
        while(diff < 0)
        {
            diff++;
            list_1->next = new ListNode(0);
            list_1 = list_1->next;
        }
        //从头开始来遍历
        list_1 = l1;
        list_2 = l2;
        bool count = false;
        ListNode* l3 = new ListNode(-1);
        ListNode* cur = l3;
        int i = 0;

        while(list_1 != NULL && list_2 != NULL)
        {
            i = count + list_1->val + list_2->val;
            cur->next = new ListNode(i % 10);  
            cur = cur->next;
            count = i >= 10?true:false;
            list_1 = list_1->next;
            list_2 = list_2->next;
        }

        if(count)
        {
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        return l3->next;
        
    }
};
// @lc code=end

