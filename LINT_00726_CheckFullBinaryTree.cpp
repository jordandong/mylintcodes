/*
A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
Conversely, there is no node in a full binary tree, which has one child node.
More information about full binary trees can be found here.

Full Binary Tree
      1
     / \
    2   3
   / \
  4   5

Not a Full Binary Tree
      1
     / \
    2   3
   / 
  4   

Example
Given tree {1,2,3}, return true
Given tree {1,2,3,4}, return false
Given tree {1,2,3,4,5} return true

Tags 
Amazon Binary Tree Breadth First Search
*/

class Solution {
public:
    /*
     * @param : the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        // write your code here
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node->left && !node->right)
                continue;
            if (node->left && node->right) {
                q.push(node->left);
                q.push(node->right);
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    /*
     * @param : the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        // write your code here
        if (!root)
            return true;
        if ((!root->left && root->right) || (root->left && !root->right))
            return false;
        return isFullTree(root->left) && isFullTree(root->right);
    }
};
