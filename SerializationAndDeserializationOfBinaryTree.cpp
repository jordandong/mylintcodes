/*
Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.

Example:
An example of testdata: Binary tree {3,9,20,#,#,15,7},  denote the following structure:

    3
   / \
  9  20
    /  \
   15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.
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
#include <sstream>

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        ostringstream os;   
        serializeHelper(root, os);
        return os.str();
    }

    void serializeHelper(TreeNode *root, ostringstream &os){
        if(!root){
            os<<"# ";
            return;
        }else{
            os<<root->val<<" ";
            serializeHelper(root->left, os);
            serializeHelper(root->right, os);
        }
    }


    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        TreeNode* root = NULL;   
        istringstream is;
        is.str(data);
        deserializeHelper(root, is);
        return root;
    }

    void deserializeHelper(TreeNode* &root, istringstream &is) {
        // write your code here
        while(is.peek() == ' ')
            is.ignore();
            
        if(is.peek() != '#'){
            int val;
            is>>val;
            root = new TreeNode(val);
            deserializeHelper(root->left, is);
            deserializeHelper(root->right,is);
        }else{
            root = NULL;
            is.ignore();
        }
    }
};
