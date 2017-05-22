/*
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in forward order, such that the 1's digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.

Example
Given 6->1->7 + 2->9->5. That is, 617 + 295.
Return 9->1->2. That is, 912.

Tags 
Linked List High Precision
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        int len1 = 0, len2 = 0, carry = 0;
        ListNode *t = l1, *res;
        while (t) {
            len1++;
            t= t->next;
        }
        t = l2;
        while (t) {
            len2++;
            t= t->next;
        }
        
        if (len1 < len2)
            t = addTwoNumbersHelper(l2, l1, len2, len1, carry);
        else
            t = addTwoNumbersHelper(l1, l2, len1, len2, carry);
        
        if (carry) {
            res = new ListNode(1);
            res->next = t;
        } else {
            res = t;
        }
        return res;
    }

private:
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int len1, int len2, int &carry) {
        if (len1 == 0 && len2 == 0)
            return NULL;

        ListNode *t, *res;
        if (len1 != len2) {
            t = addTwoNumbersHelper(l1->next, l2, --len1, len2, carry);
            res = new ListNode((carry + l1->val) % 10);
            res->next = t;
            carry = (carry + l1->val) / 10;
        } else {
            t = addTwoNumbersHelper(l1->next, l2->next, --len1, --len2, carry);
            res = new ListNode((carry + l1->val + l2->val) % 10);
            res->next = t;
            carry = (carry + l1->val + l2->val) / 10;
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        int len1 = 0, len2 = 0, len = 0;
        ListNode *t = l1, *res;
        while (t) {
            len1++;
            t= t->next;
        }
        t = l2;
        while (t) {
            len2++;
            t= t->next;
        }
        len = max(len1, len2);
        
        res = new ListNode(0);
        t = res;
        while (len) {
            t->next = new ListNode(0);
            t = t->next;
            if (len <= len1) {
                t->val += l1->val;
                l1 = l1->next;
            }
            if (len <= len2) {
                t->val += l2->val;
                l2 = l2->next;
            }
            len--;
        }
        
        t = res;
        while (t) {
            ListNode *q = t->next;
            while (q && q->val == 9) {
                q = q->next;
            }
            if (q && q->val > 9) {
                while (t != q) {
                    t->val += 1;
                    t = t->next;
                    t->val -= 10;
                }
            } else {
                t = q;
            }
        }
        if (res->val)
            return res;
        else
            return res->next;
    }
};
