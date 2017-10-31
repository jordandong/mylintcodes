/*
Given a binary search tree and a number n, find two numbers in the tree that sums up to n.

 Notice

Without any extra space.

Example
Given a binary search tree:

    4
   / \
  2   5
 / \
1   3
and a number n = 3
return [1, 2] or [2, 1]

Tags 
Binary Search Tree Google
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
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> twoSum(TreeNode * root, int n) {
        // write your code here
        set<int> st;
        vector<int> res;
        twoSumHelper(root, n, st, res);
        return res;
    }
private:
    void twoSumHelper(TreeNode * root, int n, set<int> &st, vector<int> &res) {
        if (!root)
            return;
        twoSumHelper(root->left, n, st, res);
        if (res.size())
            return;
        if (st.find(n - root->val) != st.end()) {
            res = {n - root->val, root->val};
            return;
        }
        st.insert(root->val);
        twoSumHelper(root->right, n, st, res);
    }
    
};
