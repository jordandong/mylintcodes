/*
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Example
Given a binary tree, and target = 5:
     1
    / \
   2   4
  / \
 2   3

return
[
  [1, 2, 2],
  [1, 4]
]

Tags 
Binary Tree Binary Tree Traversal
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<int> sol;
        vector<vector<int>> res;
        if (!root)
            return res;
        binaryTreePathSumHelper(root, target, sol, res);
        return res;
    }

private:
    void binaryTreePathSumHelper(TreeNode *root, int target, vector<int> &sol, vector<vector<int>> &res) {
        sol.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right && target == 0) {
            res.push_back(sol);
        }
        if (root->left)
            binaryTreePathSumHelper(root->left, target, sol, res);
        if (root->right)
            binaryTreePathSumHelper(root->right, target, sol, res);
        sol.pop_back();
    }
};
