/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        int sz_po = postorder.size();
        int sz_in = inorder.size();
        if(sz_po != sz_in || sz_po == 0)
            return NULL;

        return buildTreeHelper(inorder, postorder, sz_po - 1, 0, sz_in - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int po_id, int in_id_s, int in_id_e){
        if(in_id_e < in_id_s)
            return NULL;
        
        int val = postorder[po_id];
        int found_idx = inorder_find(val, in_id_s, in_id_e, inorder);
        TreeNode* left = buildTreeHelper(inorder, postorder, po_id - (in_id_e - found_idx) - 1, in_id_s, found_idx - 1);
        TreeNode* right = buildTreeHelper(inorder, postorder, po_id - 1, found_idx + 1, in_id_e);
        TreeNode* node = new TreeNode(val);
        node->left = left;
        node->right = right;
        return node;
    }
    
    int inorder_find(int val, int s, int e, vector<int> &inorder){
        while(s<=e){
            if(inorder[s] == val)
                return s;
            else
                s++;
        }
        return  -1;
    }
};
