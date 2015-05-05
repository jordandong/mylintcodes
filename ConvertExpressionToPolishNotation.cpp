/*
Given an expression string array, return the Polish notation of this expression. (remove the parentheses)

Example
For the expression [(5 − 6) * 7] (which represented by ["(", "5", "−", "6", ")", "*", "7"]), the corresponding polish notation is [* - 5 6 7] (which the return value should be ["*", "−", "5", "6", "7"]).

Clarification
Definition of Polish Notation:

http://en.wikipedia.org/wiki/Polish_notation
http://baike.baidu.com/view/7857952.htm

Tags Expand 
Stack
*/

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        // write your code here
        int N = expression.size();
        vector<string> res;
        stack<string> op;
        for(int i = N - 1; i >= 0; i--){
            string e = expression[i];
            if(e == ")"){
                op.push(e);
            }else if(e == "("){
               while(op.size() && op.top() != ")"){
                    res.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }else if(e == "+" || e == "-"){
                while(op.size() && (op.top() == "*" || op.top() == "/")){
                    res.push_back(op.top());
                    op.pop();
                }
                op.push(e);
            }else if(e == "*" || e == "/"){
                op.push(e);
            }else{
                res.push_back(e);
            }
        }
        while(op.size()){
            res.push_back(op.top());
            op.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
