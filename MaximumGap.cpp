/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.

Have you met this question in a real interview? Yes

Example
Given [1, 9, 2, 5], the sorted form of it is [1, 2, 5, 9], the maximum gap is between 5 and 9 = 4.

Note
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Challenge
Sort is easy but will cost O(nlogn) time. Try to solve it in linear time and space.

Tags Expand 
Greedy Sort
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        int N = nums.size();  
        if(N < 2)  
            return 0;

        int mx = nums[0];
        int mi = nums[0];
        int delta = 0;
        for (int i = 1; i < N; i++) {
            mx = max(mx, nums[i]);
            mi = min(mi, nums[i]);
        }
        
        delta = ceil(double(mx - mi)/(N - 1));
        if (delta == 0)
            return 0;

        int bin_sz = (mx - mi)/delta + 1;
        vector<int> mx_bin(bin_sz, -1);
        vector<int> mi_bin(bin_sz, -1);
        
        for (int i = 0; i < N; i++) {
            int bin = (nums[i] - mi)/delta;
            if (mi_bin[bin] == -1) {
                mi_bin[bin] = nums[i];
            } else {
                mi_bin[bin] = min(mi_bin[bin], nums[i]);
            }
            
            if (mx_bin[bin] == -1) {
                mx_bin[bin] = nums[i];
            } else {
                mx_bin[bin] = max(mx_bin[bin], nums[i]);
            }
        }
        
        int res = 0;
        int last_mx = mx_bin[0];
        for (int i = 0; i < bin_sz; i++) {
            if (mi_bin[i] == -1)
                continue;
            if (mi_bin[i] - last_mx >= res) {
                res = mi_bin[i] - last_mx;
            }
            last_mx = mx_bin[i];
        }
        return res;  
    }
};
