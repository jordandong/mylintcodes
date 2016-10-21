/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderButtom(TreeNode *root) {
        // write your code here
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> level;
        if(!root)
            return res;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            TreeNode* t = q.front();
            q.pop();
            if(t){
                level.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }else{
                res.insert(res.begin(), level);
                level.clear();
                if(q.size())
                    q.push(NULL);
            }
        }
        return res;
    }
};
