/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        //链表为空或者链表长度为1时，返回链表头结点。
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* pre = NULL;  //翻转后链表的头结点。
        ListNode* cur = head; //当前结点，设置为head。
        ListNode* last = head->next; //当前结点的下一个结点，保证不断链。
        while(last != NULL)
        {
            cur->next = pre;
            pre = cur;
            cur = last;
            last = last->next;
        }
        cur->next = pre;
        return cur;
        
        
    }
};
// @lc code=end

/*
思路整理：
① 当链表为空链表或者链表长度为1时，返回头结点。
② 当链表长度大于2时，设置三个相邻的指针，从前往后移。
  pre = NULL; cur = head; last = head->next;
  通过判断last是否为空，来遍历整个链表。

注意点：返回值的类型，此题是返回反转后的整个链表。
*/