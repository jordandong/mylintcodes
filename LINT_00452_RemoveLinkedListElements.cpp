/*
Remove all elements from a linked list of integers that have value val.

Have you met this question in a real interview? Yes

Example,
Given 1->2->3->3->4->5->3, val = 3, you should return the list as 1->2->4->5

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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur && cur->next) {
            while (cur->next && cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            cur = cur->next;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
