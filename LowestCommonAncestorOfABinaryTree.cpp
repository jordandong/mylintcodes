/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Hide Tags Tree
Hide Similar Problems (E) Lowest Common Ancestor of a Binary Search Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Code is concsie, but need to search all the nodes on the right when found
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        else if (!right)
            return left;
        else
            return root;
    }
};

//avoid unecessary search when found
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lca_count = 0;
        TreeNode* res = LCAHelper(root, p, q, lca_count);
        return lca_count == 2 ? res : NULL;

    }
    
    TreeNode* LCAHelper(TreeNode *root, TreeNode *A, TreeNode *B, int &lca_count){
        if (!root)
            return NULL;
        
        TreeNode* left_rtn = LCAHelper(root->left, A, B, lca_count);
        if (lca_count == 2 && left_rtn) // avoid the unecessary search after we found two
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
            return left_rtn ? left_rtn : right_rtn;
        }    
    }
};
