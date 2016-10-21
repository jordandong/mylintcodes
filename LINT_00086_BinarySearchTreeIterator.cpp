/*
Design an iterator over a binary search tree with the following properties:
Elements are visited in ascending order (i.e. an inorder traversal)
next() and hasNext() queries run in O(1) time in average.

Example:
For the following binary search tree, inorder traversal by using iterator is [1, 6, 10, 11, 12]
      10

    /     \

 1          11

    \           \

       6           12
       
Challenge:
Extra memory usage O(h), h is the height of the tree.
Super Star: Extra memory usage O(1)
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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
private:
    TreeNode* cur;
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        TreeNode* last = NULL;
        cur = root;
        preprocess(root, last);
        while(cur&&cur->left)
            cur=cur->left;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return cur != NULL;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode* res = cur;
        if(cur){
            cur = cur->right; // always goto next node
            while(cur && cur->left && (cur->left->val > res->val)) //if left node is unvisited
                cur = cur->left;
        }
        return res;
    }
    
    void preprocess(TreeNode *root, TreeNode *&last){
        if(!root)
            return;
        preprocess(root->left, last);
        if(last && !last->right) // set all the right node to the next node if it is NULL
            last->right = root;
        last = root;
        preprocess(root->right, last);
    }
};

//Also could be done with O(logn) or O(h) space, using a stack similar to inorder traverse
