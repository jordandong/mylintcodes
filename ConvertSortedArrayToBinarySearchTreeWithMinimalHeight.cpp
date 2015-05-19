/*
Given a sorted (increasing order) array, Convert it to create a binary tree with minimal height.

Example
Given [1,2,3,4,5,6,7], return

     4
   /   \
  2     6
 / \    / \
1   3  5   7
Note
There may exist multiple valid solutions, return any of them.

Tags Expand 
Cracking The Coding Interview Recursion Binary Tree
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
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return sortedArrayToBSTHelper(A, 0, A.size() - 1);
    }
    
    TreeNode *sortedArrayToBSTHelper(vector<int> &A, int s, int e) {
        if(s > e)
            return NULL;
        int mid = s + (e - s) / 2;
        TreeNode* node = new TreeNode(A[mid]);
        node->left = sortedArrayToBSTHelper(A, s, mid - 1);;
        node->right = sortedArrayToBSTHelper(A, mid + 1, e);
        return node;
    }
};
