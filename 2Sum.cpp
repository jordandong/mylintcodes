/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Note
You may assume that each input would have exactly one solution

Example
numbers=[2, 7, 11, 15], target=9

return [1, 2]

Challenge Expand 
1. O(1) Space, O(nlogn) Time

2. O(n) Space, O(n) Time

Tags Expand 
Array Two Pointers
*/

//O(n) Space, O(n) Time
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> mp;
        vector<int> res;
        int sz = nums.size();
        for(int i=0; i<sz; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[target - nums[i]] = i;
            }else{
                res.push_back(1 + min(mp[nums[i]], i));
                res.push_back(1 + max(mp[nums[i]], i));
            }
        }
        return res;
    }
};

