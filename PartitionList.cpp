/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode* l_h = NULL;
        ListNode* l_t = NULL;
        ListNode* g_h = NULL;
        ListNode* g_t = NULL;
    	
    	while(head){
    	    if(head->val < x){
                if(!l_h){
                    l_h = head;
                    l_t = l_h;
                }else{
                    l_t->next = head;
                    l_t = l_t->next;
                }
            }else{
                if(!g_h){
                    g_h = head;
                    g_t = g_h;
               }else{
                   g_t->next = head;
                   g_t = g_t->next;
               }
            }
            head = head->next;
        }

        if(l_h){
            l_t->next = g_h;
        }else{
            l_h = g_h;
        }
        if(g_t)
            g_t->next = NULL;
        return l_h;
    }
};
