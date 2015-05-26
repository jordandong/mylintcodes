/*
There are n coins in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins.
Could you please decide the first player will win or lose?
Have you met this question in a real interview? Yes

Example
Given array A = [3,2,2], return true.
Given array A = [1,2,4], return true.
Given array A = [1,20,4], return false.

Challenge
Follow Up Question:
If n is even. Is there any hacky algorithm that can decide whether first player will win or lose in O(1) memory and O(n) time?

Tags Expand 
Dynamic Programming Array Game Theory
*/

//T:O(N^2) S:O(N), rolling DP array
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int N = values.size();
        if (N & 0x1 == 0)
            if (firstWinEven(values))
                return true;

        int sum = 0;
        vector<vector<int>> dp(N, vector<int>(3, 0));
        for (int len = 1; len <= N; len++) {
            sum += values[len - 1];
            for (int i = 0; i + len - 1 < N; i++) {
                int a = i + 2 < N && len - 2 >= 0 ? dp[i + 2][(len - 2)%3] : 0;
                int b = i + 1 < N && len - 2 >= 0 ? dp[i + 1][(len - 2)%3] : 0;
                int c = len - 2 >= 0 ? dp[i][(len - 2)%3] : 0;
                dp[i][len%3] = max(values[i] + min(a, b), values[i + len - 1] + min(b, c));
                //take one from left or right plus min taken in next step
                //the other player is as smart as you, he will choose take one from left or right so that you always have the min left
            }
        }
        return dp[0][N%3] > sum - dp[0][N%3];
    }
    
    bool firstWinEven(vector<int>& values) {
        int odd_sum = 0;
        int even_sum = 0;
        for (int i = 0; i < values.size(); i++) {
            if (i & 0x1)
                odd_sum += values[i];
            else
                even_sum += values[i];
        }
        //if odd sum > even sum OR even sum > odd sum,
        //the first player can force the second player to choose coins at odd or even position 
        return odd_sum != even_sum;
    }
};

//T:O(N^2) S:O(N^2)
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int N = values.size();
        if (N & 0x1 == 0)
            if (firstWinEven(values))
                return true;

        int sum = 0;
        vector<vector<int>> dp(N, vector<int>(N + 1, 0));
        for (int len = 1; len <= N; len++) {
            sum += values[len - 1];
            for (int i = 0; i + len - 1 < N; i++) {
                int a = i + 2 < N && len - 2 >= 0 ? dp[i + 2][(len - 2)] : 0;
                int b = i + 1 < N && len - 2 >= 0 ? dp[i + 1][(len - 2)] : 0;
                int c = len - 2 >= 0 ? dp[i][(len - 2)] : 0;
                dp[i][len] = max(values[i] + min(a, b), values[i + len - 1] + min(b, c));
                //take one from left or right plus min taken in next step
                //the other player is as smart as you, he will choose take one from left or right so that you always have the min left
            }
        }
        return dp[0][N] > sum - dp[0][N];
    }
    
    bool firstWinEven(vector<int>& values) {
        int odd_sum = 0;
        int even_sum = 0;
        for (int i = 0; i < values.size(); i++) {
            if (i & 0x1)
                odd_sum += values[i];
            else
                even_sum += values[i];
        }
        //if odd sum > even sum OR even sum > odd sum,
        //the first player can force the second player to choose coins at odd or even position 
        return odd_sum != even_sum;
    }
};

//T:O(N^2) S:O(N^2)
//http://articles.leetcode.com/2011/02/coins-in-line.html
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int N = values.size();
        if (N & 0x1 == 0)
            if (firstWinEven(values))
                return true;

        int sum = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int j = 0; j < N; j++) {
            sum += values[j];
            for (int i = 0, n = j; n < N; i++, n++) {
                int a = i + 2 < N ? dp[i + 2][n] : 0;
                int b = i + 1 < N && n - 1 >= 0 ? dp[i + 1][n - 1] : 0;
                int c = n - 2 >= 0 ? dp[i][n - 2] : 0;
                dp[i][n] = max(values[i] + min(a, b), values[n] + min(b, c));
                //take one from left or right plus min taken in next step
                //the other player is as smart as you, he will choose take one from left or right so that you always have the min left
            }
        }
        return dp[0][N - 1] > sum - dp[0][N - 1];
    }
    
    bool firstWinEven(vector<int>& values) {
        int odd_sum = 0;
        int even_sum = 0;
        for (int i = 0; i < values.size(); i++) {
            if (i & 0x1)
                odd_sum += values[i];
            else
                even_sum += values[i];
        }
        //if odd sum > even sum OR even sum > odd sum,
        //the first player can force the second player to choose coins at odd or even position 
        return odd_sum != even_sum;
    }
};
