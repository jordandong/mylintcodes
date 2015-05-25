/*
Partition an integers array into odd number first and even number second.
Have you met this question in a real interview? Yes

Example
Given [1, 2, 3, 4], return [1, 3, 2, 4]

Challenge
Do it in-place.

Tags Expand 
Two Pointers Array
*/

//Can pass the OJ, this doesn't care the order either.
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            while (left <= right && (nums[left] & 0x1))
                ++left;
            while (left <= right && !(nums[right] & 0x1))
                --right;
            if (left <= right)
               swap(nums[left++], nums[right--]);
        }
    }
};

//OL judge didn't accept this, this should be correct since it doesn't care the order either.
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] & 0x1)
                i++;
            else
                swap(nums[i], nums[j--]);
        }
    }
};
