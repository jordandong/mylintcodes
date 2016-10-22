/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int len = 0;
        ListNode* tmp = head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        return sortedListToBSTHelper(1, len, head);
    }
    
    TreeNode* sortedListToBSTHelper(int start, int end, ListNode* &head){
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode* left = sortedListToBSTHelper(start, mid-1, head);
        TreeNode* cur = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = sortedListToBSTHelper(mid+1, end, head);
        cur->left = left;
        cur->right = right;
        return cur;
    }
};
