/*
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.

Have you met this question in a real interview? Yes
Example
Given s = "lintcode", dict = ["lint", "code"].

Return true because "lintcode" can be break as "lint code".

Tags Expand 
String Dynamic Programming
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        // write your code here
        int sz = s.length();
        bool dp[sz+1];
        char chrs[256] = {0};
       
        for(string word : dict) {
            for(char c : word) {
                chrs[c]++;
            }
        }
        for(char c : s) {
            if (chrs[c] == 0)
              return false;
        } 
  
        memset(dp, 0, (sz+1)*sizeof(bool));
        dp[0] = true;
        for(int i = 0; i<sz; i++){
            for(int j = i; j>=0; j--){
                if(dict.count(s.substr(j, i-j+1)) && dp[j]==true){
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};
