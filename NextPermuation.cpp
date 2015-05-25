/*
Given a list of integers, which denote a permutation.
Find the next permutation in ascending order.

Have you met this question in a real interview? Yes
Example
For [1,3,2,3], the next permutation is [1,3,3,2]
For [4,3,2,1], the next permutation is [1,2,3,4]

Note
The list may contains duplicate integers.

Tags Expand 
LintCode Copyright Permutation
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int sz = nums.size();
        int i = sz - 2;
        int j = sz - 1;
        
        while(i>=0 && nums[i] >= nums[i+1])
            i--;
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        
        while(j>=0 && nums[j] <= nums[i])
            j--;
            
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return nums;
    }
};
