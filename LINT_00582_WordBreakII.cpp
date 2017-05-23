/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].
A solution is ["lint code", "lint co de"].

Tags 
Dynamic Programming Backtracking
*/

//DP to avoid dup calculation
class Solution {
public:
    /**
     * @param s a string
     * @param wordDict a set of words
     */
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        // Write your code here
        vector<string> res;
        vector<bool> dp(s.length(), true); //dp[i] means start from index i, there is a solution
        wordBreakHelper(s, 0, "", wordDict, res, dp);
        return res;
    }
    void wordBreakHelper(string &s, int start, string sol, unordered_set<string> &dict, vector<string>& res, vector<bool> &dp){
        if(start == s.length()){
            if(!sol.empty())
                sol.pop_back();//pop the last space
            res.push_back(sol);
            return;
        }
        
        for(int end = start; end < s.length(); end++){
            string sub = s.substr(start, end - start + 1);
            if(dict.find(sub) == dict.end())
                continue;
            if(dp[end + 1]){ //if no solution, we continue
                int sol_num = res.size(); //sol before go further
                wordBreakHelper(s, end + 1, sol + sub + " ", dict, res, dp);
                dp[end + 1] = sol_num != res.size(); //sol after go futher, set false if no sol increasing
            }
        }
    }
};

//DP to avoid dup calculation
class Solution {
public:
    /**
     * @param s a string
     * @param wordDict a set of words
     */
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        // Write your code here
        int len = s.length();
        vector<string> res;
        vector<bool> dp(len + 1, false);//ending at length j, it can be break or not
        dp[0] = true;
        
        for(int j = 0; j < len; j++){
            for(int k = j; k >= 0; k--){
                if(wordDict.find(s.substr(k, j - k + 1)) != wordDict.end() && dp[k])
                    dp[j + 1] = true;
            }
        }
        
        if(dp[len])
            wordBreakHepler(s, "", 0, res, dp, wordDict);
        return res;
    }
    
    bool wordBreakHepler(string &s, string sol, int last, vector<string> &res, vector<bool> &dp, unordered_set<string> &dict){
        if(last == s.length()){
            res.push_back(sol);
            return true;
        }
        for(int i = last; i < s.length(); i++){
            if(!dp[i + 1])
                continue;
            string sub = s.substr(last, i - last + 1);
            if(dict.find(sub) != dict.end()){
                string sub1 = sol + (sol.size() ? (" " + sub) : sub);
                wordBreakHepler(s, sub1, i + 1, res, dp, dict);
            }
        }
        return false;
    }
};
