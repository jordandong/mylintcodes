/*
Given two strings, find the longest comment subsequence (LCS).

Your code should return the length of LCS.

Example
For "ABCD" and "EDCA", the LCS is "A" (or D or C), return 1

For "ABCD" and "EACB", the LCS is "AC", return 2

Clarification
What's the definition of Longest Common Subsequence?

    * The longest common subsequence (LCS) problem is to find the longest subsequence common to all sequences in a set of sequences (often just two). (Note that a subsequence is different from a substring, for the terms of the former need not be consecutive terms of the original sequence.) It is a classic computer science problem, the basis of file comparison programs such as diff, and has applications in bioinformatics.

    * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int sza = A.length();
        int szb = B.length();
        if(sza == 0 || szb == 0)
            return 0;

        int dp[2][sza+1];
        int c = 0;
        memset(dp, 0, sizeof(int)*2*(sza+1));
        
        for(int i = 0; i < szb; i++){
            for(int j = 0; j < sza; j++){
                if(B[i] == A[j]){
                    dp[c][j+1] = dp[c^1][j] + 1;
                }else{
                    dp[c][j+1] = max(dp[c][j], dp[c^1][j+1]);
                }
            }
            c^=1;
        }
        
        return dp[c^1][sza];
    }
};
