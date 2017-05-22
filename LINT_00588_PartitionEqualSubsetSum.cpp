/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Notice
1. Each of the array element will not exceed 100.
2. The array size will not exceed 200.

Example
Given nums = [1, 5, 11, 5], return true
two subsets: [1, 5, 5], [11]

Given nums = [1, 2, 3, 9], return false

Tags 
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param nums a non-empty array only positive integers
     * @return return true if can partition or false
     */
    bool canPartition(vector<int>& nums) {
        // Write your code here
        int sum = 0;
        for (auto &e : nums)
            sum += e;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (auto &e : nums) {
            for (int V = sum; V >= e; V--) {
                if (dp[V - e])
                    dp[V] = true;
                if (dp[sum])
                    return true;
            }
        }
        return dp[sum];
    }
};
