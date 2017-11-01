/*
Given a set of integers, write a function to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example
Given nums = [1, 6, 11, 5], return 1

// Subset1 = [1, 5, 6], sum of Subset1 = 12 
// Subset2 = [11], sum of Subset2 = 11   
// abs(11 - 12) = 1     
Tags 
Dynamic Programming Google
*/

class Solution {
public:
    /*
     * @param : the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int N = nums.size(), SUM = 0;
        for (auto e : nums)
		    SUM += e; //total sum, if there is nega input, convert it to positive first
	    bool dp[SUM + 1] = {false};
	    dp[0] = true;
	    
	    for (int i = 0; i < N; i++) {
		    for (int j = SUM; j >= nums[i]; j--)
			    dp[j] = (dp[j] || dp[j - nums[i]]); 
	    }

	    int res = SUM;
	    for (int i = 0; i <= SUM / 2; i++) {
            if(dp[i] && dp[SUM - i])
			    res = min(res, SUM - i - i);
	    }
	    return res;
    }
};

#include<cfloat>
class Solution {
public:
    /*
     * @param : the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int N = nums.size(), SUM = 0;
        for (auto e : nums)
		    SUM += e; //total sum, if there is nega input, convert it to positive first
	    bool dp[SUM + 1] = {false};
	    dp[0] = true;
	    
	    for (int i = 0; i < N; i++) {
		    for (int j = SUM; j >= nums[i]; j--)
			    dp[j] = (dp[j] || dp[j - nums[i]]); 
	    }

	    double S = SUM/2.0, res = DBL_MAX;
	    for (int i = 0; i<=(int)S; i++) {
            if(dp[i])
			    res = min(res, S - i);
	    }
	    //S1 = i; S2 = 2*S -S1 = 2*S - i
	    //ABS(S1-S2) = 2*ABS(S-i)
	    return 2 * res;
    }
};
