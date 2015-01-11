/*
Given a string s, cut s into some substrings such that every substring is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int sz = s.length();
        int dp[sz + 1];
        bool dp1[sz+1][sz+1];
        memset(dp, 0, sizeof(int)*(sz+1));
        memset(dp1, 0, sizeof(bool)*(sz+1)*(sz+1));
        dp1[0][0] = true;
        dp[0] = -1;
        
        for(int i = 0; i < sz; i++){
            dp[i+1] = INT_MAX;
            for(int j = i; j>=0; j--){
                if(s[j] == s[i] && (i - j <= 2 || dp1[j+2][i])){
                    dp[i+1] = min(dp[j] + 1, dp[i+1]);
                    dp1[j+1][i+1] = true;
                }
            }
        }
        return dp[sz];
    }
};
