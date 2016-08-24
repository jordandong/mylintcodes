/*
Throw n dices, the sum of the dices' faces is S. Given n, find the all possible value of S along with its probability.

Notice
You do not care about the accuracy of the result, we will help you to output results.

Example
Given n = 1, return [ [1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]].

Tags 
Dynamic Programming Mathematics Probability
*/

// T : O(N^2) , S : O(N)
class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> res;
        vector<vector<double>> dp(2, vector<double>(6 * n + 1));

        for (int i = 1; i <= 6; ++i)
            dp[1][i] = 1 / 6.0; //one dice, init P = 1/6
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= 6 * i; ++j) {
                dp[i % 2][j] = 0.0; //i dices and total points j, init P = 0
                for (int k = 1; k <= 6; ++k) { //ith dice needs k points
                    if (j > k)
                        dp[i % 2][j] += dp[(i - 1) % 2][j - k];
                        //(i -1)th dice P with (j - k) points * ith dice P(1/6) with k points 
                    else
                      break;
                }
                dp[i % 2][j] /= 6.0;
            }
        }

        for (int i = n; i <= 6 * n; ++i)
            res.emplace_back(i, dp[n % 2][i]);
        return res;
    }
};

