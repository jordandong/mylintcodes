/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

Notice
You may assume that each input would have exactly one solution.

Example
Given nums = [2, 7, 11, 15], target = 9
return [1, 2]

Tags 
Hash Table Two Pointers Array Amazon
*/

class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> res(2, -1);
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int sum = nums[start] + nums[end];
            if(sum == target){
                res[0] = start + 1;
                res[1] = end + 1;
                break;
            }
            sum > target ? (end--) : (start++);
        }
        return res;
    }
};

class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> mp;
        vector<int> res(2, -1);
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                res[0] = mp[nums[i]] + 1;
                res[1] = i + 1;
                break;
            }else{
                mp[target - nums[i]] = i;
            }
        }
        return res;
    }
};
