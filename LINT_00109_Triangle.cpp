/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Have you met this question in a real interview? Yes

Example
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Tags Expand 
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int n = triangle.size();
        if(!n)
            return 0;

        int dp[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        int mi = triangle[0][0];
        
        for(int i = 0; i < n; i++){
            dp[i + 1] = dp[i];
            dp[0] = dp[1];
            for(int j = i ; j>=0; j--){
                dp[j+1] = min(dp[j+1], dp[j]) + triangle[i][j];
            }
        }
        
        mi = dp[1];
        for(int k = 1; k <= n; k++)
            mi = min(mi, dp[k]);
        
        return mi;
    }
};
