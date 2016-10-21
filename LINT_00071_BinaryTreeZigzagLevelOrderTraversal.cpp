/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

Example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        vector<int> level;
        stack<TreeNode*> s[2];
        bool reverse = false;
        int c = 0;

        if(!root)
            return res;
        
        s[c].push(root);
        while(s[c].size()){
            TreeNode* t = s[c].top();
            s[c].pop();
            level.push_back(t->val);
            if(reverse){
                if(t->right)
                    s[c^1].push(t->right);
                if(t->left)
                    s[c^1].push(t->left);
            }else{
                if(t->left)
                    s[c^1].push(t->left);
                if(t->right)
                    s[c^1].push(t->right);
            }
            
            if(s[c].empty()){
                res.push_back(level);
                level.clear();
                c^=1;
                reverse=!reverse;
            }
        }
        return res;
    }
};
