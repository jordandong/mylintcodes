/*
Given an array "nums" of integers and an int "k", Partition the array (i.e move the elements in "nums") such that,
    * All elements < k are moved to the left
    * All elements >= k are moved to the right
Return the partitioning Index, i.e the first index "i" nums[i] >= k.

Note:
You should do really partition in array "nums" instead of just counting the numbers of integers smaller than k.
If all elements in "nums" are smaller than k, then return "nums.length"

Example:
If nums=[3,2,2,1] and k=2, a valid answer is 1.

Challenge:
Can you partition the array in-place and in O(n)?
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int lo = 0;
        int hi = nums.size() - 1;
        
        while(lo <= hi){
            if(nums[lo] < k)
                lo++;
            else
                swap(nums[lo], nums[hi--]);
        }
        return lo;
    }
};

//min swaps
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            while (left <= right && nums[left] < k) {
                ++left;
            } 
            while (left <= right && nums[right] >= k) {
                --right;
            }
            if (left <= right) {
               swap(nums[left++], nums[right--]);
            }
        }
        return left;
    }
};
