/*
You are given coins of different denominations and a total amount of money.
Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.

Notice
You can assume below:
1. 0 <= amount <= 5000
2. 1 <= coin <= 5000
3. the number of coins is less than 500
4. the answer is guaranteed to fit into signed 32-bit integer

Example
Given amount = 10, coins = [10], return 1

Given amount = 8, coins = [2, 3, 8], return 3
there are three ways to make up the amount:
8 = 8
8 = 3 + 3 + 2
8 = 2 + 2 + 2 + 2

Tags 
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
    int change(int amount, vector<int> &coins) {
        // write your code here
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; 0 < j && j <= amount; ++j)
                dp[j] += dp[j - coins[i]];
        }
        return dp[amount];
    }
};
