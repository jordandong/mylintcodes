/*
Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Notice
1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.

Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Tags 
Two Pointers Array
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int i = 0, k = 0;
        while (i < (int)nums.size()) {
            if (nums[i] == 0)
                i++;
            else if (i != k)
                swap(nums[i++], nums[k++]);
            else
                i++, k++;
        }
    }
};
