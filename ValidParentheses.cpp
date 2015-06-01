/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Have you met this question in a real interview? Yes

Example
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Tags Expand 
Stack
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if ( stk.size() &&
                        ( (c == ')' && stk.top() == '(') ||
                          (c == ']' && stk.top() == '[') ||
                          (c == '}' && stk.top() == '{') 
                        )){
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};
