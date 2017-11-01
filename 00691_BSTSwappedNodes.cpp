/*
In a binary search tree, (Only) two nodes are swapped. Find out these nodes and swap them. If there no node swapped, return original root of tree.

Example
Given a binary search tree:

    4
   / \
  5   2
 / \
1   3
return

    4
   / \
  2   5
 / \
1   3
Tags 
Binary Binary Tree Facebook
*/

class Solution {
public:
    /*
     * @param : the given tree
     * @return: the tree after swapping
     */
    TreeNode * bstSwappedNode(TreeNode * root) {
        // write your code here
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        TreeNode* prev = NULL;
        bstSwappedNodeHelper(root, l, r, prev);
        if (l && r)
            swap(l->val, r->val);
        return root;
    }
    
    void bstSwappedNodeHelper(TreeNode *root, TreeNode* &l, TreeNode* &r, TreeNode* &prev){
        if (!root)
            return;
        bstSwappedNodeHelper(root->left, l, r, prev);
        if(prev && root->val < prev->val){
            if(!l)
                l = prev;
            r = root;
        }
        prev = root;
        bstSwappedNodeHelper(root->right, l, r, prev);
    }
};
