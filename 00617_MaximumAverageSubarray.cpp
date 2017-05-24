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
        double l = INT_MAX, r = INT_MIN;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (nums[i] < l)
                l = nums[i]; //min possible result
            if (nums[i] > r)
                r = nums[i]; //max possible result
        }

        vector<double> sum(N + 1, 0);
        while (r - l >= 1e-6) {
            double mid = (l + r) / 2.0; // binary search
            double min_pre = 0; //
            bool check = false;
            for (int i = 1; i <= N; ++i) {
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if (i >= k && sum[i] - min_pre >= 0) {
                    check = true;
                    break;
                }
                if (i >= k)
                    min_pre = min(min_pre, sum[i - k + 1]);
            }
            if (check)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};
