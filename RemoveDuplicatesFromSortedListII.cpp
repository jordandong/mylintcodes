/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example:
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* begin = pre;
        ListNode* cur = pre;
        
        while(cur->next){
            if(cur->next->next && cur->next->val == cur->next->next->val){
                    cur = cur->next;
            }else{
                if(cur == begin){
                    cur = cur->next;
                    begin = begin->next;
                }else{
                    begin->next = cur->next->next;
                    cur = begin;
                }
            }
        }
        cur = pre->next;
        delete pre;
        return cur;
    }
};
