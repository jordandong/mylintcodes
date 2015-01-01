/*
Given two strings, find the longest common substring.

Return the length of it.

Note
The characters in substring should occur continiously in original string. This is different with subsequnce.

Example
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int sza = A.length();
        int szb = B.length();
        int dp[sza+1];//dp[i] means length i of A, the current LCS
        memset(dp, 0 , sizeof(int)*(sza+1));
        int mx = 0;
        for(int i = 0; i < szb; i++){
            for(int j = sza -1; j>=0; j--){
                if(A[j] == B[i]){
                    dp[j+1] = dp[j] + 1;
                }else{
                    dp[j+1] = 0;
                }
                mx = max(dp[j+1], mx);
            }
        }
        return mx;
    }
};
