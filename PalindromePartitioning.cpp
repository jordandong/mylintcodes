/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:
given, s = "aab",
Return,
  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string> > res;
        vector<string> sol;
        int n = s.length();
        vector<vector<int> > mp(n, vector<int>(n,0)); // avoid dup caculation
        partitionHelper(s, 0, res, sol, mp);
        return res;
    }

    void partitionHelper(string &s, int start, vector<vector<string> > &res, vector<string> &sol, vector<vector<int> > &mp){
        if(start == s.length()){
            res.push_back(sol);
            return;
        }

        for(int i=start; i<s.length(); i++){
            if(isPal(start, i, s, mp)){
               sol.push_back(s.substr(start, i-start+1));
               partitionHelper(s, i+1, res, sol, mp);
               sol.pop_back();
            }
        }
    }

    bool isPal(int start, int end, string &s, vector<vector<int> > &mp){
        if(mp[start][end] == 1)
            return true;
        else if(mp[start][end] == 2)
            return false;
        int i = start;
        int j = end;
        while(j>=i){
            if(s[j--] != s[i++]){
                mp[start][end] = 2;
                return false;
            }
        }
        mp[start][end] = 1;
        return true;
    }
};
