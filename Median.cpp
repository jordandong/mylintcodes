/*
Given a unsorted array with integers, find the median of it. 
A median is the middle number of the array after it is sorted. 
If there are even numbers in the array, return the N/2-th number after sorted.

Example:
Given [4, 5, 1, 2, 3], return 3
Given [7, 9, 4, 5], return 5

Challenge: O(n) time.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int sz = nums.size(); 
        if(sz == 0)
            return -1;
        return medianHelper(nums, 0, sz-1, (sz+1)/2);
    }
    
    int medianHelper(vector<int> &nums, int lo, int hi, int k){
        int i = lo;
        int j = hi - 1;
        int mid = nums[lo + (k-1)];
        swap(nums[lo + (k-1)], nums[hi]);
        while(i<=j){
            if(nums[i] > mid)
                swap(nums[i], nums[j--]);
            else
                i++;
        }
        swap(nums[i], nums[hi]);
        
        int less = i - lo + 1;
        if(less == k)
            return nums[i];
        if(less > k)
            return medianHelper(nums, lo, i-1, k);
        else{
            return medianHelper(nums, i+1, hi, k - less);
        }
    }
};
