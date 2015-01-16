/*
Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.

Note:
The subarray should contain at least one number

Example
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
        int sz = nums.size();
        if(sz < k)
            return -1;

        int dp[sz+1][k+1]; //dp[i][j] means ending at length i and select j subarrays , the max sum
        for(int i = 0; i <= sz; i++){
            dp[i][0] = 0;
            for(int j = 1; j <= k; j++)
                dp[i][j] = INT_MIN;
        }

        for(int i = 1; i <= sz; i++){
            for(int j = 1; j <= min(i, k); j++){
                dp[i][j] = dp[i-1][j];
                int sum = 0;
                for(int t = i; t > j-1; t--) {//calculate new added subarray sum from the end
                    sum += nums[t-1];
                    dp[i][j] = max(dp[i][j], dp[t-1][j-1] + sum);
                    //update max, subarrays sum of previous k-1 selection at first length t-1 plus the last subarray 
                    sum = (sum<0 ? 0:sum);
                }
            }
        }
        return dp[sz][k];
    }
};
