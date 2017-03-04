/*
Reverse a linked list from position m to n.

Note:
Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

Example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.

Challenge:
Reverse it in-place and in one-pass
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
 
//One Pass 
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode* prehead = new ListNode(-1);
        ListNode* prehead_tail = NULL;
        ListNode* rev_head = NULL;
        ListNode* rev_tail = NULL;
        ListNode* tail = NULL;
        ListNode* cur = prehead;
        prehead->next = head;
        
        int cnt = 0;
        while(cur){
            ListNode* tmp = cur;
            if(cnt + 1 == m){
                rev_head = cur->next;
                prehead_tail = cur;
            }
            if(cnt == n)
                tail = cur->next;
            cur = cur->next;
            if(cnt + 1 == m || cnt == n)
                tmp->next = NULL;
                
            if(cnt >=m && cnt<=n){
                tmp->next = rev_tail;
                rev_tail = tmp;
            }
            cnt++;
        }
        
        prehead_tail->next = rev_tail;
        rev_head->next = tail;
        
        cur = prehead->next;
        delete prehead;
        return cur;
    }
};

//Two Pass
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode* prehead = new ListNode(-1);
        ListNode* prehead_tail = NULL;
        ListNode* rev_head = NULL;
        ListNode* rev_tail = NULL;
        ListNode* rev_cur = NULL;
        ListNode* tail = NULL;
        ListNode* cur = prehead;
        prehead->next = head;
        
        int cnt = 0;
        while(cnt <=n && cur){
            ListNode* tmp = cur;
            if(cnt + 1 == m){
                rev_head = cur->next;
                prehead_tail = cur;
            }
            if(cnt == n)
                tail = cur->next;
            cur = cur->next;
            if(cnt + 1 == m || cnt == n)
                tmp->next = NULL;
            cnt++;
        }
        
        rev_cur = rev_head;
        while(rev_cur){
            ListNode* tmp = rev_cur;
            rev_cur = rev_cur->next;
            tmp->next = rev_tail;
            rev_tail = tmp;
        }
        
        prehead_tail->next = rev_tail;
        rev_head->next = tail;
        
        cur = prehead->next;
        delete prehead;
        return cur;
    }
};
