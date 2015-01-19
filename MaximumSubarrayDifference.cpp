/*
Given an array with integers.
Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.
Return the largest difference.

Note:
The subarray should contain at least one number

Example:
For [1, 2, -3, 1], return 6

Challenge:
O(n) time and O(n) space.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int sz = nums.size();
        if(sz < 2)
            return -1;
        
        vector<int> mx_so_far(sz, 0);
        vector<int> mi_so_far(sz, 0);
        int mx = nums[0], mi = nums[0];
        int sum_mx = 0, sum_mi = 0;
        int mx_global = 0;
        for(int i = 0; i < sz; i++){
            sum_mx+=nums[i];
            sum_mi+=nums[i];
            
            mx = max(mx, sum_mx);
            mx_so_far[i] = mx;
            sum_mx = (sum_mx < 0 ? 0 : sum_mx);
            
            mi = min(mi, sum_mi);
            mi_so_far[i] = mi;
            sum_mi = (sum_mi > 0 ? 0 : sum_mi);
        }
        
        mx = nums[sz-1];
        mi = nums[sz-1];
        sum_mx = 0;
        sum_mi = 0;
        for(int i = sz-1; i > 0; i--){
            sum_mx+=nums[i];
            sum_mi+=nums[i];
            
            mx = max(mx, sum_mx);
            mx_global = max(mx_global, abs(mx - mi_so_far[i-1]));
            sum_mx = (sum_mx < 0 ? 0 : sum_mx);
            
            mi = min(mi, sum_mi);
            mx_global = max(mx_global, abs(mi - mx_so_far[i-1]));
            sum_mi = (sum_mi > 0 ? 0 : sum_mi);
        }
        return mx_global;
    }
};
