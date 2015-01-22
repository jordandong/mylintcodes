/*
Given an integer array with no duplicates. A max tree building on this array is defined as follow:
--The root is the maximum number in the array
--The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array.

Example:
Given [2, 5, 6, 0, 3, 1], the max tree is
              6

            /    \

         5       3

       /        /   \

     2        0     1

Challenge:
O(n) time complexity
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        TreeNode* max_root = NULL;
        for(int v : A){
            TreeNode* node = new TreeNode(v);
            if(max_root == NULL){
                max_root = node;
            }else if(v > max_root->val){ // the bigger one is the root
                node->left = max_root;
                max_root = node;
            }else{
                TreeNode* tmp = max_root; // insert the new one in the right child
                while(tmp){
                    if(!tmp->right){
                        tmp->right = node;
                        break;
                    }
                    if(tmp->right->val < v){ // all the smaller subtree should be the left child of new nodes 
                        node->left = tmp->right;
                        tmp->right = node;
                        break;
                    }
                    tmp = tmp->right;// new node is the right child of the bigger node
                }
            }
        }
        return max_root;
    }
};
