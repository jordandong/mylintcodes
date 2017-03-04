/*
Given a root of Binary Search Tree with unique value for each node.  Remove the node with given value. If there is no such a node with given value in the binary search tree, do nothing. You should keep the tree still a binary search tree after removal.

Example:
Given binary search tree:
          5

       /    \

    3          6

 /    \

2       4

Remove 3, you can either return:
          5

       /    \

    2          6

      \

         4

or :
          5

       /    \

    4          6

 /   

2
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        TreeNode* *cur = &root; //need to use address, otherwise cannot update the oringnal tree nodes
        while(*cur){
            if((*cur)->val > value){
                cur = &((*cur)->left);
            }else if((*cur)->val < value){
                cur = &((*cur)->right);
            }else{
                TreeNode* tmp = NULL;
                if((*cur)->left == NULL){
                    tmp = (*cur)->right;
                    delete *cur;
                    *cur = tmp;
                }else if((*cur)->right == NULL){
                    tmp = (*cur)->left;
                    delete *cur;
                    *cur = tmp;
                }else{
                    TreeNode **tmp_cur = cur;
                    TreeNode* p = NULL;
                    cur = &((*cur)->right);
                    //find the smallest on the right child OR find the biggest on the left child
                    while((*cur)->left){
                        p = *cur;
                        cur = &((*cur)->left);
                    }
                    
                    if(p){
                        (*tmp_cur)->val = (*cur)->val;
                        p->left = NULL;
                        delete *cur;
                    }else{
                        delete *tmp_cur;
                        *tmp_cur = *cur;
                    }
                }
            }
        }
        return root;
    }
};
