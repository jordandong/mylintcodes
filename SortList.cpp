/*
Sort a linked list in O(n log n) time using constant space complexity.

Example:
Given 1-3->2->null, sort it to 1->2->3->null.
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        int len = 0;
        if(!head)
            return head;

        ListNode* cur = head;
        while(cur){
            len++;
            cur=cur->next;
        }
        return sortListPartition(head, len);
    }
    
    ListNode *sortListPartition(ListNode* &head, int len){
        if(len == 1){
            ListNode* tmp = head;
            head = head->next;
            tmp->next = NULL;
            return tmp;
        }
        return sortListMerge(sortListPartition(head, len/2), sortListPartition(head, len - len/2));
        
    }
    
    ListNode *sortListMerge(ListNode* l1, ListNode* l2){
        ListNode* prehead = new ListNode(-1);
        ListNode* cur = prehead;
        while(l1&&l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        
        if(l1)
            cur->next = l1;
        else if(l2)
            cur->next = l2;
        
        cur = prehead->next;
        delete prehead;
        return cur;
    }
};
