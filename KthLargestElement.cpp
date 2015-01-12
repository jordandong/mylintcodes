/*
Find K-th largest element in an array.

Note:
You can swap elements in the array

Example:
In array [9,3,2,4,8], the 3th largest element is 4

Challenge:
O(n) time, O(1) space
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(k > nums.size())
            return -1;
        return kthLargestElementHelper(k, nums, 0, nums.size()-1);
    }

    int kthLargestElementHelper(int k, vector<int> &nums, int start, int end){
        int lo = start;
        int hi = end -1;
        while(lo <= hi){
            if(nums[lo] <= nums[end]){
            //if(nums[lo] >= nums[end]){  --> kthSmallestElement
                swap(nums[lo], nums[hi--]);
            }else{
                lo++;                 
            }
        }
        swap(nums[end], nums[lo]);
        int less = lo - start;
        if(less >= k){
            return kthLargestElementHelper(k, nums, start, lo-1);
        }else if(k == less + 1){
            return nums[lo];
        }else{
            return kthLargestElementHelper(k-less, nums, lo, end);
        }
    }
};
