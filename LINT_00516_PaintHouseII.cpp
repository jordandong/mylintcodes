/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Notice:
All costs are positive integers.

Example:
Given n = 3, k = 3, costs = [[14,2,11],[11,14,5],[14,3,10]] return 10
house 0 is color 2, house 1 is color 3, house 2 is color 2, 2 + 5 + 3 = 10

Challenge:
Could you solve it in O(nk)?

Tags:
Dynamic Programming Facebook
*/

class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int> >& costs) {
        // Write your code here
        int N = costs.size();
        if (N == 0)
            return 0;
        int K = costs[0].size();
        if (K <= 0)
            return 0;

        vector<int> dp(K, 0);
        int m_color = -1, m1 = INT_MAX, m2 = INT_MAX;
        int p_color = -1, p_m1 = 0, p_m2 = 0;
        for (int i = 0; i < N;++i) {
            m_color = -1, m1 = INT_MAX, m2 = INT_MAX;
            for (int c = 0; c < K; c++) {
                //the min cost at i with color c is the cost of painting color c plus the min cost in previous setp at i - 1
                //if at i - 1, the color is the same using second min value, otherwise using the first min value
                dp[c] = costs[i][c] + (p_color == c ? p_m2 : p_m1);
                m2 = min(dp[c], m2); //update the second min value
                if (dp[c] <= m1) {
                    m_color = c; //record the first min value's color
                    m2 = m1; //update second min value
                    m1 = dp[c]; //update the first min value
                }
            }
            p_color = m_color;
            p_m1 = m1;
            p_m2 = m2;
        }
        return m1;
    }
};
