/*
You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order, such that the 1’s digit is at the head of the list.Write a function that adds the two numbers and returns the sum as a linked list.

Example
Given two lists, 3->1->5->null and 5->9->2->null, return 8->0->8->null
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
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode* pre = new ListNode(-1);
        ListNode* tmp = pre;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            tmp->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            tmp = tmp->next;
        }
        
        while(l1){
            int sum = l1->val + carry;
            tmp->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            tmp = tmp->next;
        }
        
        while(l2){
            int sum = l2->val + carry;
            tmp->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            tmp = tmp->next;
        }
        
        if(carry){
            tmp->next = new ListNode(carry);
        }
        
        tmp = pre->next;
        delete(pre);
        return tmp;
    }
};
