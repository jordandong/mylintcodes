/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note
You are not suppose to use the library's sort function for this problem. 

Example
Clarification
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int lo = 0;
        int hi = nums.size()-1;
        int cur = 0;
        if(hi < 0)
            return;
        while(cur <= hi){
            if(nums[cur] == 2){
                swap(nums[cur], nums[hi]);
                hi--;
            }else if(nums[cur] == 1){
                cur++;
            }else if(nums[cur] == 0){
                swap(nums[lo], nums[cur]);
                lo++;
                cur++;
            }
        }
    }
};
