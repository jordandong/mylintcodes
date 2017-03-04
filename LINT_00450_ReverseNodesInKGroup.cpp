/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed. Only constant memory is allowed.

Have you met this question in a real interview? Yes

Example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Tags Expand
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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        int len = 0;
        ListNode *cur = head, *nextNode = NULL;
        ListNode *preHead = NULL, *preTail = NULL;
        int round = 0;
        
        while (cur) {
            len++;
            cur = cur->next;
        }
        round = len / k;
        if (round == 0 || round == len)
            return head;
            
        cur = head;
        while (round--) {
            ListNode *curHead = NULL, *curTail = NULL;
            for (int i = 0; i < k; i++) {
                nextNode = cur->next;
                if (i == 0) {
                    curTail = cur;
                    curHead = cur;
                } else {
                    cur->next = curHead;
                    curHead = cur;
                }
                cur = nextNode;
            }
            if (preHead == NULL)
                preHead = curHead;
            if (preTail)
                preTail->next = curHead;
            preTail = curTail;
        }
        preTail->next = cur;
        return preHead;
    }
};
