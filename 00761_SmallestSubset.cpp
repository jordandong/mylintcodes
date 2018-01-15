/*
Given an array of non-negative integers.
Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.

Example
Given nums = [3, 1, 7, 1], return 1
Given nums = [2, 1, 2], return 2

Tags 
Greedy Array
*/

class Solution {
public:
    /**
     * @param nums: an array of non-negative integers
     * @return: minimum number of elements
     */
    int minElements(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        int sum = 0, total = 0;
        for (auto n : nums)
            sum += n;
        for (int i = nums.size() - 1; i >= 0; i--) {
            total += nums[i];
            if (total > sum / 2)
                return nums.size() - i;
        }
        return 0;
    }
};
