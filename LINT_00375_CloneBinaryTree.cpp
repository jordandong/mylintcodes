/*
For the given binary tree, return a deep copy of it.

Example
Given a binary tree:
     1
   /  \
  2    3
 / \
4   5

return the new binary tree with same structure and same value:
     1
   /  \
  2    3
 / \
4   5

Tags 
Binary Tree
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
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if (!root)
            return NULL;
        TreeNode* clone_root = new TreeNode(root->val);
        stack<TreeNode*> stk, clone_stk;
        stk.push(root);
        clone_stk.push(clone_root);
        while (!stk.empty() && !clone_stk.empty()) {
            TreeNode *r = stk.top();
            stk.pop();
            TreeNode *c_r = clone_stk.top();
            clone_stk.pop();
            if (r->left) {
                c_r->left = new TreeNode(r->left->val);
                stk.push(r->left);
                clone_stk.push(c_r->left);
            }
            if (r->right) {
                c_r->right = new TreeNode(r->right->val);
                stk.push(r->right);
                clone_stk.push(c_r->right);
            }
        }
        return clone_root;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if (root == NULL)
            return NULL;

        auto clone_root = new TreeNode(root->val);
        clone_root->left = cloneTree(root->left);
        clone_root->right = cloneTree(root->right);
        
        return clone_root;
    }
};
