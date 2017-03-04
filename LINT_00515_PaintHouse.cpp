/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Notice:
All costs are positive integers.

Example:
Given costs = [[14,2,11],[11,14,5],[14,3,10]] return 10
house 0 is blue, house 1 is green, house 2 is blue, 2 + 5 + 3 = 10

Tags
LinkedIn Dynamic Programming
*/

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    enum COLOR {
        RED,
        BLUE,
        GREEN
    };

    int minCost(vector<vector<int> >& costs) {
        // Write your code here
        vector<vector<int> > dp(2, vector<int>(3, 0));
        int i = 0;
        while(i < costs.size()) {
            dp[(i + 1) & 1][RED] = costs[i][RED] + min(dp[i & 1][BLUE], dp[i & 1][GREEN]);
            dp[(i + 1) & 1][BLUE] = costs[i][BLUE] + min(dp[i & 1][RED], dp[i & 1][GREEN]);
            dp[(i + 1) & 1][GREEN] = costs[i][GREEN] + min(dp[i & 1][RED], dp[i & 1][BLUE]);
            i++;
        }
        return min(min(dp[i & 1][RED], dp[i & 1][BLUE]), dp[i & 1][GREEN]);
    }
};

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    enum COLOR {
        RED,
        BLUE,
        GREEN
    };

    int minCost(vector<vector<int> >& costs) {
        // Write your code here
        int N = costs.size();
        vector<vector<int> > dp(N + 1, vector<int>(3, 0));

        for (int i = 0; i < N;++i) {
            dp[i + 1][RED] = costs[i][RED] + min(dp[i][BLUE], dp[i][GREEN]);
            dp[i + 1][BLUE] = costs[i][BLUE] + min(dp[i][RED], dp[i][GREEN]);
            dp[i + 1][GREEN] = costs[i][GREEN] + min(dp[i][RED], dp[i][BLUE]);
        }
        return min(min(dp[N][RED], dp[N][BLUE]), dp[N][GREEN]);
    }
};
