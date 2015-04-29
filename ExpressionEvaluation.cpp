/*
Given an expression string array, return the final result of this expression

Example
For the expression (2*6-(23+7)/(1+2)), input is

[
  "2", "*", "6", "-", "(",
  "23", "+", "7", ")", "/",
  (", "1", "+", "2", ")"
],
return 2

Note
The expression contains only integer, +, -, *, /, (, ).

Tags Expand 
Stack
*/

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        stack<string> op;
        stack<double> val;
        //convert into rPolish expression and calulate
        for(auto &e : expression){
            if(e == "("){
                op.push(e);
            }else if(e == "-" || e == "+"){
                while(op.size() && (op.top() == "-" || op.top() == "*" || op.top() == "/")){
                    evaluateExpressionHelper(op.top(), val);
                    op.pop();
                }
                op.push(e);
            } else if(e == "*" || e == "/"){
                while(op.size() && (op.top() == "/")){
                    evaluateExpressionHelper(op.top(), val);
                    op.pop();
                }
                op.push(e);
            }else if(e == ")"){
                while(op.size() && op.top() != "("){
                    evaluateExpressionHelper(op.top(), val);
                    op.pop();
                }
                op.pop();
            }else{
                double num = 0;
                bool sign = false;
                for(auto &c : e){
                    if(c == '-')
                        sign = true;
                    else
                        num = 10*num + (double)(c - '0');
                }
                if(sign)
                    num *= -1;
                val.push(num);
            }
        }
        while(op.size()){
            evaluateExpressionHelper(op.top(), val);
            op.pop();
        }
        
        if(val.size())
            return val.top();
        else
            return 0;
    }
    
    void evaluateExpressionHelper(string &ops, stack<double> &val){
        //Calulate rPolish expression
        double a = val.top();
        val.pop();
        double b = val.top();
        val.pop();
        if(ops == "+")
            val.push(b + a);
        if(ops == "-")
            val.push(b - a);
        if(ops == "*")
            val.push(b * a);
        if(ops == "/")
            val.push(b / a);
    }
};

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        stack<string> stk;
        vector<string> rp;

        //convert into rPolish expression
        for(auto &e : expression){
            if(e == "("){
                stk.push(e);
            }else if(e == "-" || e == "+"){
                while(stk.size() && (stk.top() == "-" || stk.top() == "*" || stk.top() == "/")){
                    rp.push_back(stk.top());
                    stk.pop();
                }
                stk.push(e);
            } else if(e == "*" || e == "/"){
                while(stk.size() && (stk.top() == "/")){
                    rp.push_back(stk.top());
                    stk.pop();
                }
                stk.push(e);
            }else if(e == ")"){
                while(stk.size() && stk.top() != "("){
                    rp.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }else{
                rp.push_back(e);
            }
        }
        while(stk.size()){
            rp.push_back(stk.top());
            stk.pop();
        }
        
        //Calulate rPolish expression
        stack<double> stk1;
        for(auto & e : rp){
            if(e == "+" || e == "-" || e == "*" || e == "/"){
                double a = stk1.top();
                stk1.pop();
                double b = stk1.top();
                stk1.pop();
                if(e == "+")
                    stk1.push(b + a);
                if(e == "-")
                    stk1.push(b - a);
                if(e == "*")
                    stk1.push(b * a);
                if(e == "/")
                    stk1.push(b / a);
            } else {
                double num = 0;
                bool sign = false;
                for(auto &c : e){
                    if(c == '-')
                        sign = true;
                    else
                        num = 10*num + (double)(c - '0');
                }
                if(sign)
                    num *= -1;
                stk1.push(num);
            }
        }
        if(stk1.size())
            return stk1.top();
        else
            return 0;
    }
};
