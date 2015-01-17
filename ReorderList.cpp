/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.

Example:
For example,
Given 1->2->3->4->null, reorder it to 1->4->2->3->null.
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        ListNode* slow = prehead;
        ListNode* fast = head;
        ListNode* tmp = NULL;
        
	    while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }//find the header of second half
        fast = slow->next;//fast is the header of second half
        slow->next = NULL;
        slow = NULL;

        while(fast){
            tmp = fast;
            fast = fast->next;
            tmp->next = slow;
            slow = tmp;
        }// reverse the second half, slow is the new header of second half

        fast = prehead->next;//fast is the header of the first half
        prehead->next = NULL;
        tmp = prehead;
        while(fast && slow){
            tmp->next = fast;
            tmp = tmp->next;
            fast = fast->next;
            tmp->next = slow;
            tmp = tmp->next;
            slow = slow->next;
        }//merge two lists
        if(fast)
            tmp->next = fast;
        if(slow)
            tmp->next = slow;
    }
};
