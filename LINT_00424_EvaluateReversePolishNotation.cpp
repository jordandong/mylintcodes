/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Have you met this question in a real interview? Yes

Example
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

Tags Expand 
Queue
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if(tokens.size() == 0)
            return 0;
        stack<int> s;
        for(auto &t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(t == "+")
                    s.push(b + a);
                if(t == "-")
                    s.push(b - a);
                if(t == "*")
                    s.push(b * a);
                if(t == "/")
                    s.push(b / a);
            }else{
                s.push(str2num(t));
            }
        }
        return s.top();
    }
    
    int str2num(string &s) {
        int num = 0;
        int sign = 1;
        for(auto& c : s){
            if(c == '-')
                sign = -1;
            else
                num = 10 * num + (c - '0');
        }
        return num * sign;
    }
};
