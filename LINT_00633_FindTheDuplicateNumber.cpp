/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist.
Assume that there is only one duplicate number, find the duplicate one.

Notice
1. You must not modify the array (assume the array is read only).
2. You must use only constant, O(1) extra space.
3. Your runtime complexity should be less than O(n^2).
4. There is only one duplicate number in the array, but it could be repeated more than once.

Example
Given nums = [5,5,4,3,2,1] return 5
Given nums = [5,4,4,3,2,1] return 4

Tags 
Binary Search Two Pointers Array Bloomberg
*/

class Solution {
public:
    /**
     * @param nums an array containing n + 1 integers which is between 1 and n
     * @return the duplicate one
     */
    int findDuplicate(vector<int>& nums) {
        // Write your code here
        int slow = nums.size() - 1;
        int fast = slow;
        //Similar to finding the duplicated element in linked list with a circle
        do {
            slow = nums[slow] - 1;
            fast = nums[fast] - 1;
            fast = nums[fast] - 1;
        } while (slow != fast); //met if there is a circle
        
        fast = nums.size() - 1; //reset one pointer to the begining
        while (slow != fast) { //find the duplicated location
            slow = nums[slow] - 1;
            fast = nums[fast] - 1;
        }
        return slow + 1;
    }
};
