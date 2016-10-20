/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

Example:
For example, given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:
(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int sz = nums.size();
        vector<vector<int> > res;
        unordered_map<int, vector<pair<int, int> > > data;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz; i++)
            for(int j = i+1; j < sz; j++)
                data[nums[i]+nums[j]].push_back(make_pair(i,j));
                
        for(int i = 0; i < sz - 3; i++){
            if(i > 0 && nums[i]==nums[i-1])//reduce dup for the 1st element
                continue;   
            for(int j = i+1; j < sz - 2; j++){
                if(j > i+1 && nums[j]==nums[j-1])//reduce dup for the 2nd element
                    continue;   
                int left = target - nums[i] - nums[j];
                if(data.find(left) == data.end())
                    continue;
                vector<pair<int, int> > &v = data[left];
                bool added = false;
                for(int k = 0; k < v.size(); k++){
                    if(v[k].first <= j)//reduce the dup across four elements
                        continue;
                    if(!added || nums[v[k].first] != res.back()[2]){ //reduce dup for the last two elements
                        vector<int> sol;
                        sol.push_back(nums[i]);
                        sol.push_back(nums[j]);
                        sol.push_back(nums[v[k].first]);
                        sol.push_back(nums[v[k].second]);
                        res.push_back(sol);
                        added = true;
                    }
                }
            }
        }
        return res;
    }
};
