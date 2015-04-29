/*
Sort a linked list using insertion sort.

Example
Given 1->3->2->0->null, return 0->1->2->3->null.

Tags Expand 
Sort Linked List
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(head){
            cur = dummy;
            while(cur->next && cur->next->val <= head->val)
                cur = cur->next;
            ListNode *tmp = cur->next;
            cur->next = head;
            head = head->next;
            cur->next->next = tmp;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
