/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example
Given binary tree A={3,9,20,#,#,15,7}, B={3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        int h;
        return isBalHelper(root, h);
    }
    
    bool isBalHelper(TreeNode *root, int &h){
        if(!root){
            h = 1;
            return true;
        }
        int l_h = 0;
        int r_h = 0;
        bool l = isBalHelper(root->left, l_h);
        bool r = isBalHelper(root->right, r_h);
        h = max(l_h, r_h) + 1;
        return l&&r&&abs(l_h-r_h)<=1;
    }
};
