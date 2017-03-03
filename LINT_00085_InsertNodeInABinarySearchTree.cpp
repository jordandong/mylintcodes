/*
Given a binary search tree  and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

Example
Given binary search tree as follow:

     2

  /    \

1        4

         /   

       3 

after Insert node 6, the tree should be:

     2

  /    \

1        4

         /   \ 

       3        6

Challenge
Do it without recursion
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        TreeNode *t = root;
        while(t){
            if(node->val > t->val){
                if(!t->right){
                    t->right = node;
                    return root;
                }else{
                    t = t->right;
                }
            }else{
                if(!t->left){
                    t->left = node;
                    return root;
                }else{
                    t = t->left;
                }
            }
        }
        root = node;
        return root;
    }
};
