/*
Convert a binary search tree to doubly linked list with in-order traversal.

Example
Given a binary search tree:
    4
   / \
  2   5
 / \
1   3

return 1<->2<->3<->4<->5

Tags 
Linked List
*/

/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 *         this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        DoublyListNode *prev = NULL;
        DoublyListNode *head = NULL;
        bstToDoublyListHelper(root, prev, head);
        return head;
    }
private:
    void bstToDoublyListHelper(TreeNode *root, DoublyListNode* &prev, DoublyListNode* &head) {
        if (!root)
            return;
        bstToDoublyListHelper(root->left, prev, head);
        DoublyListNode* cur = new DoublyListNode(root->val);
        cur->prev = prev;
        if (prev)
            prev->next = cur;
        else
            head = cur;
        prev = cur;
        bstToDoublyListHelper(root->right, prev, head);
    }
};
