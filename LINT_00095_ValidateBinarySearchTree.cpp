/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example
An example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        long long pre_val = (long long)INT_MIN - 1;
        return isValidBSTHelper(root, pre_val);
    }
    
    bool isValidBSTHelper(TreeNode* root, long long &pre_val){
        if(!root)
            return true;
            
        bool l = isValidBSTHelper(root->left, pre_val);
        if(pre_val >= root->val || !l){
            return false;
        }else{
            pre_val = root->val;
        }
        bool r = isValidBSTHelper(root->right, pre_val);
        return r;
    }
};
