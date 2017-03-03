/*
Find the nth to last element of a singly linked list. 
The minimum number of nodes in list is n.

Example:
Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode* fast = head;
        ListNode* slow = head;
        while(n && fast){
            fast=fast->next;
            n--;
        }
        if(n>0)
            return NULL;
        
        while(fast){
            slow = slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
