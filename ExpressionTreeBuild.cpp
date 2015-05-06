/*
The structure of Expression Tree is a binary tree to evaluate certain expressions. All leaves of the Expression Tree have an number string value. All non-leaves of the Expression Tree have an operator string value.

Now, given an expression array, build the expression tree of this expression, return the root of this expression tree.

Example
For the expression (2*6-(23+7)/(1+2)) (which can be represented by ["2" "*" "6" "-" "(" "23" "+" "7" ")" "/" "(" "1" "+" "2" ")"]). The expression tree will be like

                 [ - ]
             /          \
        [ * ]              [ / ]
      /     \           /         \
    [ 2 ]  [ 6 ]      [ + ]        [ + ]
                     /    \       /      \
                   [ 23 ][ 7 ] [ 1 ]   [ 2 ] .
After building the tree, you just need to return root node [-].

Clarification
See wiki: Expression Tree

Tags Expand 
Stack Binary Tree
*/

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        vector<string> rpn = convertToRPN(expression);
        stack<ExpressionTreeNode*> stk;
        for(auto e : rpn){
            if(e == "+" || e == "-" || e == "*" || e == "/"){
                ExpressionTreeNode* r = stk.top();
                stk.pop();
                ExpressionTreeNode* l = stk.top();
                stk.pop();
                ExpressionTreeNode* node = new ExpressionTreeNode(e);
                node->left = l;
                node->right = r;
                stk.push(node);
            }else{
                ExpressionTreeNode* node = new ExpressionTreeNode(e);
                stk.push(node);
            }
        }
        if(stk.size())
            return stk.top();
        else
            return NULL;
    }

    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> res;
        stack<string> op;
        for(auto e : expression){
            if(e == "("){
                op.push(e);
            }else if(e == ")"){
               while(op.size() && op.top() != "("){
                    res.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }else if(e == "+" || e == "-"){
                while(op.size() && op.top() != "("){
                    res.push_back(op.top());
                    op.pop();
                }
                op.push(e);
            }else if(e == "*" || e == "/"){
                while(op.size() && (op.top() == "*" || op.top() == "/")){
                    res.push_back(op.top());
                    op.pop();
                }
                op.push(e);
            }else{
                res.push_back(e);
            }
        }
        while(op.size()){
            res.push_back(op.top());
            op.pop();
        }
        return res;
    }
};
