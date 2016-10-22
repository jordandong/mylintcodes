/*
There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.
Could you please decide the first player will win or lose?
Have you met this question in a real interview? Yes

Example
Given values array A = [1,2,2], return true.
Given A = [1,2,4], return false.

Tags Expand 
Dynamic Programming Array Game Theory
*/

//T:O(N) S:O(1), Rolling DP Array
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int N = values.size();
        vector<int> dp(5, 0);
        int sum = 0;
        //take one plus min taken in next step OR take two plus min taken in next step
        //the other player is as smart as you, he will choose take one or two so that you always have the min left
        for (int i = N - 1; i >= 0; i--) {
            sum += values[i];
            dp[i%5] = max(values[i] + min(dp[(i + 2) %5], dp[(i + 3)%5]), 
                       values[i] + values[i + 1] + min(dp[(i + 3)%5], dp[(i + 4)%5]));
        }
        return dp[0] > sum - dp[0];
    }
};

//T:O(N) S:O(N)
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int N = values.size();
        vector<int> dp(N + 4, 0);
        int sum = 0;
        //take one plus min taken in next step OR take two plus min taken in next step
        //the other player is as smart as you, he will choose take one or two so that you always have the min left
        for (int i = N - 1; i >= 0; i--) {
            sum += values[i];
            dp[i] = max(values[i] + min(dp[i + 2], dp[i + 3]), 
                       values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]));
        }
        return dp[0] > sum - dp[0];
    }
};
