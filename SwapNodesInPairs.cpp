/*
Given a linked list, swap every two adjacent nodes and return its head.

Have you met this question in a real interview? Yes

Example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Challenge
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Tags Expand 
Linked List
*/

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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode *cur = head, *next = NULL;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (cur && cur->next) {
            next = cur->next->next;
            tail->next = cur->next;
            tail = tail->next;
            tail->next = cur;
            tail = tail->next;
            cur = next;
        }
        tail->next = cur;
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};
