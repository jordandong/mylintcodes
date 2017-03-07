/*
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<long long, int> mp;
        vector<int> res;
        long long t = 0;
        int sz = nums.size();
        for(int i=0; i<sz; i++){
            t+=nums[i];
            if(t==0){
                res.push_back(0);
                res.push_back(i);
                return res;
            }else if(mp.find(t)!=mp.end()){
                res.push_back(mp.find(t)->second + 1);
                res.push_back(i);
                return res;
            }else{
                mp[t] = i;    
            }
        }
        return res;
    }
};
