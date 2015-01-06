/*
Given a list of integers, which denote a permutation.

Find the previous permutation in ascending order.

Note
The list may contains duplicate integers.

Example
For [1,3,2,3], the previous permutation is [1,2,3,3]

For [1,2,3,4], the previous permutation is [4,3,2,1]
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int sz = nums.size();
        int i = sz - 2;
        while(i >=0 && nums[i] <= nums[i+1])
            i--;

        if (i == -1){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        
        int j = sz - 1;
        while(j > i && nums[j] >= nums[i])
            j--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return nums;
    }
};
