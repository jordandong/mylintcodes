/*
Write a program to find the node at which the intersection of two singly linked lists begins.

Have you met this question in a real interview? Yes

Example,
The following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Note,
1. If the two linked lists have no intersection at all, return null.
2. The linked lists must retain their original structure after the function returns.
3. You may assume there are no cycles anywhere in the entire linked structure.

Challenge,
Your code should preferably run in O(n) time and use only O(1) memory.

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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        ListNode *A = headA, *B = headB;
        bool A_first_pass = true, B_first_pass = true;
        while (A && B) {
            if (A == B)
                return A;
            A = A->next;
            B = B->next;
            if (A == NULL && A_first_pass)
                A = headB;
            if (B == NULL && B_first_pass)
                B = headA;
        }
        return NULL;
    }
};
