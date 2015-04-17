/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.

Tags Expand 
Dynamic Programming Subarray
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int sz = nums.size();
        if(sz == 0)
            return 0;
        int maxi = nums[0], mini = nums[0], res = nums[0];
        for(int i = 1; i < sz; i++){
            int maxi_copy = max(1, maxi);	
            if(nums[i] > 0){
                maxi = maxi_copy * nums[i];    
                mini *= nums[i];
            }else{
                maxi = mini * nums[i];
                mini = maxi_copy * nums[i];    
            }
            res = max(res, maxi);
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int sz = nums.size();
        if(sz == 0)
            return 0;
        int maxi = nums[0], mini = nums[0];
        int last_maxi, last_mini;
        int res = maxi;
        for(int i = 1; i < sz; i++){
            last_maxi = maxi;
            last_mini = mini;
            if(nums[i] > 0){
                maxi = max(last_maxi*nums[i], nums[i]);
                mini = min(last_mini*nums[i], nums[i]);
            }else{
                maxi = max(last_mini*nums[i], nums[i]);
                mini = min(last_maxi*nums[i], nums[i]);
            }
            res = max(res, maxi);
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int sz = nums.size();
        if(sz == 0)
            return 0;
        int maxi = nums[0], mini = nums[0];
        int last_maxi, last_mini;
        int res = maxi;
        for(int i = 1; i < sz; i++){
            last_maxi = maxi;
            last_mini = mini;
            maxi = max(max(last_maxi*nums[i], last_mini*nums[i]), nums[i]);
            mini = min(min(last_maxi*nums[i], last_mini*nums[i]), nums[i]);
            res = max(res, maxi);
        }
        return res;
    }
};
