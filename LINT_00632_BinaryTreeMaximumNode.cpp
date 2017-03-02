/*
Find the maximum node in a binary tree, return the node.

Example
Given a binary tree:
     1
   /   \
 -5     2
 / \   /  \
0   3 -4  -5 
return the node with value 3.

Tags 
Binary Tree
*/

class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        if (!root)
            return root;
        TreeNode* l = maxNode(root->left);
        TreeNode* r = maxNode(root->right);
        TreeNode* res = root;
        if (l)
            res = l->val >= res->val ? l : res;
        if (r)
            res = r->val >= res->val ? r : res;
        return res;
    }
};
