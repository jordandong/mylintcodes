/*
Given a linked list and two values v1 and v2. Swap the two nodes in the linked list with values v1 and v2. It's guaranteed there is no duplicate values in the linked list. If v1 or v2 does not exist in the given linked list, do nothing.

Have you met this question in a real interview? Yes

You should swap the two nodes with values v1 and v2. Do not directly swap the values of the two nodes.

Example:
Given 1->2->3->4->null and v1 = 2, v2 = 4.
Return 1->4->3->2->null.

Tags:
Linked List
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
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode* n1 = NULL, *n2 = NULL, *curNode = NULL, * preNodeTail = NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        curNode = dummy;
        while (curNode && curNode->next) {
            if ((curNode->next->val == v1 || curNode->next->val == v2) && !n1) {
                n1 = curNode->next;
                preNodeTail = curNode;
            } else if (curNode->next->val == v1 || curNode->next->val == v2) {
                n2 = curNode->next;
                if (n1->next == n2) {
                    n1->next = n2->next;
                    n2->next = n1;
                    preNodeTail->next = n2;
                } else {
                    ListNode * tmp = n1->next;
                    curNode->next = n1;
                    n1->next = n2->next;
                    n2->next = tmp;
                    preNodeTail->next = n2;
                }
                break;
            }
            curNode = curNode->next; 
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
