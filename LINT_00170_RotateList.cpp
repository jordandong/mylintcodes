/*
Given a list, rotate the list to the right by k places, where k is non-negative.

Example:
Given 1->2->3->4->5->null and k=2
return 4->5->1->2->3->null
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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(!head)
            return head;
        
        int len = 0;
        ListNode* cur = head;
        ListNode* f=head;
        ListNode* s=head;
        
        while(cur){
            len++;
            cur = cur->next;
        }
        
        k%=len;
        
        while(k){
            f= f->next;
            k--;
        }
        
        while(f->next){
            s=s->next;
            f=f->next;
        }
        
        f->next = head;
        cur = s->next;
        s->next = NULL;
        return cur;
    }
};
