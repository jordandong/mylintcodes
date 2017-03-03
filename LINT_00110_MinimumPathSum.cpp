/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note
You can only move either down or right at any point in time.
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        
        int c = 0;
        int dp[2][n+1];
        memset(dp, 0 , 2*sizeof(int)*(n+1));
        
        for(int i = 0; i < m ; i++){
            dp[c][0] = dp[c^1][1];
            for(int j = 0; j < n; j++){
                dp[c][j+1] = ( (i==0) ? dp[c][j] : min(dp[c^1][j+1], dp[c][j])) + grid[i][j];
            }
            c^=1;
        }
        
        return dp[c^1][n];
    }
};
