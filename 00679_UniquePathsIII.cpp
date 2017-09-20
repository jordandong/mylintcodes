/*
Follow up for "Unique Paths II": http://lintcode.com/en/problem/unique-paths-ii/
Now each grid contains a value, so each path also has a value.
Find the sum of all the unique values paths.

Example
For example,
[
  [1,1,2],
  [1,2,3],
  [3,2,4]
]

There are 2 unique value path:
[1,1,2,3,4] = 11
[1,1,2,2,4] = 10

return 21

Tags 
Dynamic Programming
*/

class Solution {
public:
    /*
     * @param : an array of arrays
     * @return: the sum of all unique weighted paths
     */
    int uniqueWeightedPaths(vector<vector<int>>& grid) {
        // write your codes here
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        unordered_set<int> st;
        vector<vector<unordered_set<int>>> dp(m + 1, vector<unordered_set<int>>(n + 1, st));
        dp[0][1].insert(0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto e : dp[i][j + 1])
                    dp[i + 1 ][j + 1].insert(e + grid[i][j]);
                for (auto e : dp[i + 1][j])
                    dp[i + 1 ][j + 1].insert(e + grid[i][j]);
            }
        }
        int res = 0;
        for (auto e : dp[m][n])
            res += e;
        return res;
    }
};
