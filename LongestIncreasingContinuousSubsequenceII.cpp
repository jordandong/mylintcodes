/*
Give you an integer matrix (with row size n, column size m)，find the longest increasing continuous subsequence in this matrix. (The definition of the longest increasing continuous subsequence here can start at any row or column and go up/down/right/left any direction).
Have you met this question in a real interview? Yes

Example
Given a matrix:
[
  [1 ,2 ,3 ,4 ,5],
  [16,17,24,23,6],
  [15,18,25,22,7],
  [14,19,20,21,8],
  [13,12,11,10,9]
]
return 25

Tags Expand 
Dynamic Programming
*/

//T:O(M*N) S:O(M*N)
class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        int M = A.size();
        if (M == 0)
            return 0;
        int N = A[0].size();
        if (N == 0)
            return 0;
        
        // dp[i][j] means len of longest increasing continuous subsequence starting with A[i][j]
        vector<vector<int> > dp(M, vector<int>(N, 0));
        int res = 0;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j] == 0)
                    res = max(res, LICSIIHelper(A, i, j, INT_MIN, dp));
            }
        }
        
        return res;
    }
    
    int LICSIIHelper(vector<vector<int>> &A, int i, int j, int last_val, vector<vector<int>> &dp) {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] <= last_val)
            return 0;
        
        if (dp[i][j] > 0)
            return dp[i][j];
        
        dp[i][j] = max(dp[i][j], 1 + LICSIIHelper(A, i + 1, j, A[i][j], dp));
        dp[i][j] = max(dp[i][j], 1 + LICSIIHelper(A, i - 1, j, A[i][j], dp));
        dp[i][j] = max(dp[i][j], 1 + LICSIIHelper(A, i, j + 1, A[i][j], dp));
        dp[i][j] = max(dp[i][j], 1 + LICSIIHelper(A, i, j - 1, A[i][j], dp));
        return dp[i][j];
    }
};
