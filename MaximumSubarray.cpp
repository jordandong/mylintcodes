/*
Given an array of integers, find a contiguous subarray which has the largest sum.

Note
The subarray should contain at least one number

Example
For example, given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Challenge
Can you do it in time complexity O(n)?
*/

class Solution {
public:    
    /**
     * @paGiven an array of integers, find a contiguous subarray which has the largest sum.

Note
The subarray should contain at least one number

Example
For example, given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Challenge
Can you do it in time complexity O(n)?
*/ram nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int sz = nums.size();
        if(sz ==0)
            return 0;
        int sum = 0;
        int mx = nums[0];
        for(int e : nums){
            sum+=e;
            mx = sum>mx ? sum:mx;
            sum = sum<0 ? 0:sum;
        }
        return mx;
    }
};
