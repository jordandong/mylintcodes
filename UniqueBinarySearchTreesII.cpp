/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

Example:
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
 //Using DP to avoid duplicated calculation, 18 ms
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        vector<vector<void*> > dp(n+1, vector<void*>(n+1, NULL));
        vector<TreeNode*> rtn;
        rtn = *generateTreesHelper(1, n, dp);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][j])
                    delete (vector<TreeNode*>*)dp[i][j];
            }
        }
        return rtn;
    }
    
    vector<TreeNode *>* generateTreesHelper(int start, int end, vector<vector<void*> > &dp){
        vector<TreeNode*>* res = new vector<TreeNode*>();
        if(start > end || start == 0){
            res->push_back(NULL);
            if(dp[0][0])
                delete res;
            else
                dp[0][0] = res;
            return (vector<TreeNode*>*)dp[0][0];
        }

        if(dp[start][end])
            return (vector<TreeNode*>*)dp[start][end];
        for(int i = start; i <= end; i++){
            vector<TreeNode *> *left =  generateTreesHelper(start, i-1, dp);
            vector<TreeNode *> *right =  generateTreesHelper(i+1, end, dp);
            for(int l = 0; l < left->size(); l++){
                for(int r = 0; r < right->size(); r++){
                    TreeNode* node = new TreeNode(i);
                    node->left = (*left)[l];
                    node->right = (*right)[r];
                    res->push_back(node);
                }
            }
        }
        dp[start][end] = res;
        return res;
    }
};

#if 0
//lots of duplicated calculation, 45 ms
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generateTreesHelper(1, n);
    }
    
    vector<TreeNode *> generateTreesHelper(int start, int end){
        vector<TreeNode*> res;
        if(start > end || start == 0){
            res.push_back(NULL);
            return res;
        }
        
        for(int i = start; i <= end; i++){
            vector<TreeNode *> left =  generateTreesHelper(start, i-1);
            vector<TreeNode *> right =  generateTreesHelper(i+1, end);
            for(int l = 0; l < left.size(); l++){
                for(int r = 0; r < right.size(); r++){
                    TreeNode* node = new TreeNode(i);
                    node->left = left[l];
                    node->right = right[r];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
#endif
