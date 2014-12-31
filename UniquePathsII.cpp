/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note
m and n will be at most 100.

Example
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if(n == 0)
            return 0;
    
        int dp[2][n+1];
        memset(dp, 0 , sizeof(int)*2*(n+1));
        dp[0][1] = 1;
        int c = 1;
        for(int i = 1; i<= m; i++){
            for(int j = 1 ; j<=n; j++){
                if(obstacleGrid[i-1][j-1])
                    dp[c][j] = 0;
                else
                    dp[c][j]=dp[c^1][j]+dp[c][j-1];
            }
            c = c^1;
        }
        return dp[c^1][n];
    }
};
