/*
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x.
You win the game when you guess the number I picked.

\Example
Given n = 10, I pick 8.
First round: You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round: You guess 9, I tell you that it's lower. You pay $9.
Game over. 8 is the number I picked.
You end up paying $5 + $7 + $9 = $21.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
So when n = 10, return16

Tags 
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        // Write your code here
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int i = n; i > 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};

class Solution {
public:
    /**
     * @param n an integer
     * @return how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        // Write your code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return getMoneyAmountHelper(dp, 1, n);
    }
    
    int getMoneyAmountHelper(vector<vector<int>> &dp, int lo, int hi){
        if (lo >= hi) //found the number
            return 0;
        if(dp[lo][hi])
            return dp[lo][hi];
        int res = INT_MAX;
        for (int k = lo; k <= hi; k++) { //pick k and go to next decision part (left or right)
            int tmp = k + max(getMoneyAmountHelper(dp, lo, k - 1), getMoneyAmountHelper(dp, k + 1, hi));
            res = min(res, tmp);
        }
        dp[lo][hi] = res;
        return res;
    }
};
