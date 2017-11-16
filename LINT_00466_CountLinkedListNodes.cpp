/*
Count how many nodes in a linked list.

Example
Given 1->3->5, return 3.

Tags 
Linked List
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
    /*
     * @param head: the first node of linked list.
     * @return: An integer
     */
    int countNodes(ListNode * head) {
        // write your code here
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
};

