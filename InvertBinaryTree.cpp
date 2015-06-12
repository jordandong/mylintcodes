/*
Invert a binary tree.

Have you met this question in a real interview? Yes

Example
  1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4

Challenge
Do it in recursion is acceptable, can you do it without recursion?

Tags Expand 
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
 
//Non-Recursion
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode *t = q.front();
            q.pop();
            if (!t)
                continue;
            q.push(t->left);
            q.push(t->right);
            swap(t->left, t->right);
        }
    }
};

//Recursion
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (!root)
            return;
        swap(root->left, root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};
