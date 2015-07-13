/*
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Example:
        4
    /     \
  3         7
          /     \
        5         6
For 3 and 5, the LCA is 4.
For 5 and 6, the LCA is 7.
For 6 and 7, the LCA is 7.
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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        int lca_count = 0;
        TreeNode* res = LCAHelper(root, A, B, lca_count);
        return lca_count == 2 ? res:NULL;
    }
    
    TreeNode* LCAHelper(TreeNode *root, TreeNode *A, TreeNode *B, int &lca_count){
        if(!root)
            return NULL;
        
        TreeNode* left_rtn = LCAHelper(root->left, A, B, lca_count);
        if(lca_count == 2 && left_rtn) // avoid the unecessary search after we found two
            return left_rtn;
        TreeNode* right_rtn = LCAHelper(root->right, A, B, lca_count);
        
        if(left_rtn && right_rtn){
            return root;
        }else if(root == A || root == B){
            if(root == A && root == B)
                lca_count++;
            lca_count++;
            return root;
        }else{
            return left_rtn?left_rtn:right_rtn;
        }    
    }
    
};

 //should be failed in certain cases since the value may be duplicated
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        int lca_count = 0;
        TreeNode* res = LCAHelper(root, A, B, lca_count);
        return lca_count == 2 ? res:NULL;

    }
    
    TreeNode* LCAHelper(TreeNode *root, TreeNode *A, TreeNode *B, int &lca_count){
        if(!root)
            return NULL;
        
        TreeNode* left_rtn = LCAHelper(root->left, A, B, lca_count);
        if(lca_count == 2 && left_rtn) // avoid the unecessary search after we found two
            return left_rtn;
        TreeNode* right_rtn = LCAHelper(root->right, A, B, lca_count);
        
        if(left_rtn && right_rtn){
            return root;
        }else if(root->val == A->val || root->val == B->val){
            if(root->val == A->val && root->val == B->val)
                lca_count++;
            lca_count++;
            return root;
        }else{
            return left_rtn?left_rtn:right_rtn;
        }    
    }
};
