/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int sz1 = word1.length();
        int sz2 = word2.length();
        int dp[2][sz1 + 1];
        int c = 0;
        dp[c][0] = 0;

        for(int i = 0; i<sz1; i++)
            dp[c][i+1] = i+1;

        for(int i = 0; i<sz2; i++){
            dp[c^1][0] = i+1;
            for(int j = 0; j<sz1; j++){
                dp[c^1][j+1] = min(1 + min(dp[c^1][j], dp[c][j+1]), dp[c][j] + (word1[j]!=word2[i])); 
            }
            c^=1;
        }
        return dp[c][sz1];
    }
};
