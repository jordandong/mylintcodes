/*
Implement a function to check if a linked list is a palindrome.

Have you met this question in a real interview? Yes

Example,
Given 1->2->1, return true

Challenge,
Could you do it in O(n) time and O(1) space?

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
 
//T: O(N) S:O(1)
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* rvt = NULL;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            if (rvt == NULL) {
                rvt = slow;
                slow = slow->next;
                rvt->next = NULL;
            } else {
                ListNode* tmp = slow->next;
                slow->next = rvt;
                rvt = slow;
                slow = tmp;
            }
        }
        
        if (fast)
            slow = slow->next;//slow is the begin of 2nd half
            
        while (slow && rvt && slow->val == rvt->val) {
            rvt = rvt->next;
            slow = slow->next;
        }
        return !slow && !rvt;
    }
};
