/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.size()==0)
            return 0;
        int lo = prices[0];
        int mx = 0;
        
        for(auto e : prices){
            if(e < lo){
                lo = e;
            }else{
                mx = max(mx, e-lo);  
            }
        }
        return mx;
    }
};
