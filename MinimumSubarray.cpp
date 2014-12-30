/*
Given an array of integers, find the subarray with smallest sum.

Return the sum of the subarray.

Note
The subarray should contain at least one integer.

Example
For [1, -1, -2, 1], return -3
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int sz = nums.size();
        if(sz = 0)
            return 0;
        int mi = nums[0];
        int sum = 0;
        for(int e : nums){
            sum+=e;
            if(sum < mi){
                mi = sum;
            }
            if(sum > 0){
                sum = 0;
            }
        }
        return mi;
    }
};
