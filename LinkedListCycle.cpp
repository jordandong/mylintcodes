/*
Given a linked list, determine if it has a cycle in it.
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && slow){
            fast = fast->next;
            slow = slow->next;
            if(fast){
                fast = fast->next;
            }else{
                return false;
            }
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
