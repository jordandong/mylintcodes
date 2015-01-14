/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example:
S = "rabbbit", T = "rabbit"
Return 3.
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int l_s = S.length();
        int l_t = T.length();
        
        int c = 0;
        int dp[2][l_s+1];
        memset(dp, 0, sizeof(int)*2*(l_s + 1));
        for(int i = 0; i <= l_s; i++)
            dp[c][i] = 1;
        
        for(int i = 0; i < l_t; i++){
            dp[c^1][0] = 0;
            for(int j = 0; j < l_s; j++){
                if(S[j] == T[i])
                    dp[c^1][j+1] = dp[c][j] + dp[c^1][j]; // select current j  + pass current j
                else
                    dp[c^1][j+1] = dp[c^1][j]; // pass current j
            }
            c^=1;
        }
        return dp[c][l_s];
    }
};
