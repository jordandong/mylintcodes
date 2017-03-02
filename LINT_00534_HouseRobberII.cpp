/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention.
This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Notice,
This is an extension of House Robber.

Example,
nums = [3,6,4], return 6

Tags 
Dynamic Programming Microsoft
*/

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        int N = nums.size();
        return max(robHelper(nums, 0, N - 2), robHelper(nums, 1, N - 1));//rob 1st OR don't rob 1st
    }
    
    int robHelper(vector<int> &nums, int start, int end) {
        if (end == 0)
            return nums[end];
        if (end < 0)
            return 0;
        int rob_mx = 0;
        int no_rob_mx = 0;
        for(int i = start; i <= end; i++){
            int rob_mx_tmp = no_rob_mx + nums[i];
            no_rob_mx = max(rob_mx, no_rob_mx);
            rob_mx = rob_mx_tmp;
        }
        return max(rob_mx, no_rob_mx);
    }
};
