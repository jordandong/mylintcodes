/*
Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.

Example
For s1 = "aabcc" s2 = "dbbca"

    - When s3 = "aadbbcbcac", return true.

    - When s3 = "aadbbbaccc", return false.

Challenge
O(n^2) time or better
*/


class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int sz1 = s1.length();
        int sz2 = s2.length();
        int sz3 = s3.length();
        
        if(sz3 != sz1+sz2)
            return false;
        
        int dp[sz1 + 1][sz2 + 1];
        dp[0][0] = true;
        for(int i = 1; i<=sz1; i++){
            if(s1[i-1] == s3[i-1] && dp[i-1][0])
                dp[i][0] = true;
            else
                dp[i][0] = false;
        }
        
        for(int i = 1; i<=sz2; i++){
            if(s2[i-1] == s3[i-1] && dp[0][i-1])
                dp[0][i] = true;
            else
                dp[0][i] = false;
        }
        
        for(int i=1; i<=sz1; i++){
            for(int j=1; j<=sz2; j++){
                if((s3[i+j-1] == s1[i-1] && dp[i-1][j])  || (s3[i+j-1] == s2[j-1] && dp[i][j-1]))
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
        return dp[sz1][sz2];
    }
};
