/*
Given a linked list, remove the nth node from the end of list and return its head.

Note:
The minimum number of nodes in list is n.

Example:
Given linked list: 1->2->3->4->5->null, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5->null.

Challenge:
O(n) time
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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode* prehead = new ListNode(-1);
        ListNode* slow = prehead;
        ListNode* fast = head;
        prehead->next = head;
        while(n && fast){
            fast = fast->next;
            n--;
        }
        if(n!=0)
            return head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next?slow->next->next:NULL;
        slow = prehead->next;
        delete prehead;
        return slow;
    }
};
