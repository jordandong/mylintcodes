/*
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters.
Output all possible results.

Example
Given the string "123"
return [["1","2","3"],["12","3"],["1","23"]]

Tags 
Backtracking Depth First Search
*/

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<string> sol;
        vector<vector<string>> res;
        splitStringHelper(s, 0, sol, res);
        return res;
    }
    
    void splitStringHelper(string& s, int idx, vector<string> &sol, vector<vector<string>> &res) {
        int N = s.length();
        if (idx >= N) {
            res.push_back(sol);
            return;
        }
        
        sol.push_back(s.substr(idx, 1));
        splitStringHelper(s, idx + 1, sol, res);
        sol.pop_back();
        
        if (idx + 1 < N) {
            sol.push_back(s.substr(idx, 2));
            splitStringHelper(s, idx + 2, sol, res);
            sol.pop_back();
        }
    }
};
