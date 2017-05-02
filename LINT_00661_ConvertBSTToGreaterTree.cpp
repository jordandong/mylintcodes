/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example
Given a binary search Tree {5,2,3}:

              5
            /   \
           2     13
Return the root of new tree

             18
            /   \
          20     13
Tags 
Binary Tree Binary Search Tree Amazon
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
     * @param root the root of binary tree
     * @return the new root
     */
    TreeNode* convertBST(TreeNode* root) {
        // Write your code here
        int sum = 0;
        convertBSTHelper(root, sum);
        return root;
    }
private:
    void convertBSTHelper(TreeNode* root, int &sum) {
        if (!root)
            return;
        convertBSTHelper(root->right, sum);
        root->val += sum;
        sum = root->val;
        convertBSTHelper(root->left, sum);
    }

};
