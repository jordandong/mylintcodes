/*
There are n coins in a line. Two players take turns to take one or two coins from right side until there are no more coins left. The player who take the last coin wins.
Could you please decide the first play will win or lose?

Example
n = 1, return true.
n = 2, return true.
n = 3, return false.
n = 4, return true.
n = 5, return true.
n = 6, return false.

Challenge
O(1) time and O(1) memory

Tags Expand 
Greedy Dynamic Programming Array Game Theory
*/

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        /*
        vector<bool> dp(n + 1, true);
        dp[0] = false;
        for (int i = 3; i <= n; i++)
            dp[i] = !(dp[i - 1]&&dp[i - 2]);
        return dp[n];
        */
        return n%3 != 0;
    }
};
