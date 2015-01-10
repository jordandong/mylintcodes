/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

Example
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int sz = nums.size();
        if(sz < 3)
            return sz;	
        int tail = 2;
        int cur = 2;
        while(cur < sz){
            if(nums[cur]==nums[tail-1] && nums[cur]==nums[tail-2]){
                cur++;
            }else{
               swap(nums[cur++], nums[tail++]);    
            }   
        }
        return tail;
    }
};
