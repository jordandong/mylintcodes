/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Example
Challenge
Follow up:
Can you solve it without using extra space?
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        ListNode* s = head;
        ListNode* f = head;
        while(s && f){
            s = s->next;
            f = f->next;
            if(!f)
                return NULL;
            f = f->next;
            if(s == f){
                break;
            }else if(!s || !f){
                return NULL;   
            }
        }
        
        s = head;
        while(s != f){
            s=s->next;
            f=f->next;
        }
        
        return s;
    }
};
