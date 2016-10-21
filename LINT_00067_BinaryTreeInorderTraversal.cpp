/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
 

return [1,3,2].

Challenge
Can you do it without recursion?
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top();
            stk.pop();
            if(t){
                stk.push(t->right);
                stk.push(t);
                stk.push(t->left);
            }else if(!stk.empty()){
                res.push_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};
