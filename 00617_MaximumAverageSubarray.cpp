/*
Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.

Notice
It's guaranteed that the size of the array is greater or equal to k.

Example
Given nums = [1, 12, -5, -6, 50, 3], k = 3
Return 15.667 // (-6 + 50 + 3) / 3 = 15.667

Tags 
Binary Search Subarray Google
*/

class Solution {
public:
    /**
     * @param nums an array with positive and negative numbers
     * @param k an integer
     * @return the maximum average
     */
    double maxAverage(vector<int>& nums, int k) {
        // Write your code here
        int i = 0, N = nums.size();
        double sum = 0, mx = 0;
        for (int j = 0; j < k; j++)
            sum += nums[j];
        mx = sum/k;
        while (i + k < N ) {
            sum -= nums[i];
            sum += nums[i + k];
            i++;
            mx = max(mx, sum/k);
        }
        return mx;
    }
};
