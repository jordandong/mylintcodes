/*
Given an expression string array, return the Reverse Polish notation of this expression. (remove the parentheses)

Example
For the expression [3 - 4 + 5] (which denote by ["3", "-", "4", "+", "5"]), return [3 4 - 5 +] (which denote by ["3", "4", "-", "5", "+"])

Tags Expand 
Stack
*/

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
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
