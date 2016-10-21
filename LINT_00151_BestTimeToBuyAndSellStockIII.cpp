/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int sz = prices.size();
        vector<int> sell(sz, 0);
        vector<int> buy(sz, 0);
        int mx, mi;
        if(sz == 0)
            return 0;

        mi = prices[0];
        sell[0] = 0;
        for(int i=1; i<sz; i++){
            mi = min(mi, prices[i]);
            sell[i] = max(sell[i-1], prices[i] - mi);
        }
        
        mx = prices[sz-1];
        buy[sz-1] = 0;
        for(int i=sz-2; i>=0; i--){
            mx = max(mx, prices[i]);
            buy[i] = max(buy[i+1], mx - prices[i]);
        }
        
        mx = 0;
        for(int i=0; i<sz; i++){
            mx = max(mx, buy[i]+sell[i]);
        }
        return mx;
    }
};
