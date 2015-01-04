/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
     int maxPathSum(TreeNode *root) {
        // write your code here
        if(!root)
            return 0;
        int mx = root->val;
        maxPathSumHelper(root, mx);
        return mx;
    }
     
    int maxPathSumHelper(TreeNode *root, int &mx) {
        // write your code here
        if(!root)
            return 0;
        int l = maxPathSumHelper(root->left, mx);
        int r = maxPathSumHelper(root->right, mx);
        mx = max(mx, root->val + (l>0?l:0) + (r>0?r:0));
        int m = max(l, r);
        return root->val + (m>0?m:0);
    }
};
