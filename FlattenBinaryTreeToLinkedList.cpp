/*
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Have you met this question in a real interview? Yes

Example,
              1
               \
     1          2
    / \          \
   2   5    =>    3
  / \   \          \
 3   4   6          4
                     \
                      5
                       \
                        6
Note,
Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.

Challenge,
Do it in-place without any extra memory.

Tags Expand 
Binary Tree Depth First Search
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
//in place 
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                if(cur->right){//cut right subtree of cur and paste it to the rightmost of left subtree 
                    TreeNode *t = cur->left;
                    while(t->right)
                        t = t->right;
                    t->right = cur->right;
                }
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
