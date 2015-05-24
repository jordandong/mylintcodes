/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

Have you met this question in a real interview? Yes

Example
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Challenge
The replacement must be in-place, do not allocate extra memory.

Tags Expand 
Permutation Array
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int N = nums.size();
        if (N == 0)
            return;
        int i = N - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if(i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
            
        int j = N - 1;
        while (j > i && nums[j] <= nums[i])
            j--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
