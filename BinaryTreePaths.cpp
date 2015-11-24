/*
Given a binary tree, return all root-to-leaf paths.

Have you met this question in a real interview? Yes

Example
Given the following binary tree:
   1
 /   \
2     3
 \
  5
  
All root-to-leaf paths are:
[
  "1->2->5",
  "1->3"
]

Tags Expand 
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        string sol = "";
        vector<string> res;
        binaryTreePathsHelper(root, sol, res);
        return res;
    }
    
    void binaryTreePathsHelper(TreeNode* root, string &sol, vector<string> &res) {
        if (!root)
            return;
        int len = sol.length();
        if (len == 0)
            sol += to_string(root->val);
        else
            sol +=("->" + to_string(root->val));
        if (!root->left && !root->right)
            res.push_back(sol);
        binaryTreePathsHelper(root->left, sol, res);
        binaryTreePathsHelper(root->right, sol, res);
        sol.erase(len, sol.length() - len);
    }
};
