/*
Given a sequence of integers, find the longest increasing subsequence (LIS).
You code should return the length of the LIS.

Example:
For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3
For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4

Challenge:
Time complexity O(n^2) or O(nlogn)

Clarification
What's the definition of longest increasing subsequence?
    * The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  
    * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int sz = nums.size();
        if(sz == 0 || sz == 1)
            return sz;
        int dp[sz];
        int mx = 1;
        dp[0] = 1;
        
        for(int i = 1; i < sz; i++){
            dp[i] = 1;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] >= nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    mx = max(mx, dp[i]);
                }
            }
        }
        
        return mx;
    }
};
