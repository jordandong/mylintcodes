/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Have you met this question in a real interview? Yes

Example
Given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"

Tags Expand 
String Backtracking Recursion Zenefits Google
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        string sol = "";
        vector<string> res;
        generateParenthesisHelper(n, n, sol, res);
        return res;
    }
    
    void generateParenthesisHelper(int l, int r, string &sol, vector<string> &res) {
        if (r == 0) {
            res.push_back(sol);
            return;
        }
        if (l > 0) {
            sol.push_back('(');
            generateParenthesisHelper(l - 1, r, sol, res);
            sol.pop_back();
        }
        if (r > l) {
            sol.push_back(')');
            generateParenthesisHelper(l, r - 1, sol, res);
            sol.pop_back();
        }
    }
};
