/*
Check if two binary trees are identical. Identical means the two binary trees have the same structure and every identical position has the same value.

Have you met this question in a real interview? Yes

Example
    1             1
   / \           / \
  2   2   and   2   2
 /             /
4             4
are identical.

    1             1
   / \           / \
  2   3   and   2   3
 /               \
4                 4
are not identical.

Tags Expand  Binary Tree
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        stack<TreeNode*> stka, stkb;
        stka.push(a);
        stkb.push(b);
        while (stka.size() && stkb.size()) {
            TreeNode *ta = stka.top();
            stka.pop();
            TreeNode *tb = stkb.top();
            stkb.pop();
            if (!ta || !tb) {
                if (ta != tb)	
                    return false;
                else
                    continue; 
             }
	     if (ta->val != tb->val)
                 return false;
             stka.push(ta->right);
             stka.push(ta->left);
             stkb.push(tb->right);
             stkb.push(tb->left);
        }
        return stka.size() == stkb.size();
    }
};
