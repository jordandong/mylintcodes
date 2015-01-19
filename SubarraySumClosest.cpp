/*
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Example:
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4]

Challenge:
O(nlogn) time
*/

bool pair_cmp(pair<int, long long> a, pair<int, long long> b){
    return a.second < b.second;
}

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<pair<int, long long> > sum;
        vector<int> res(2, -1);
        int sz = nums.size();
        long long diff;
        long long t = 0;
        if(sz == 0)
            return res;

        sum.push_back(make_pair(-1, 0));
        for(int i = 0; i < sz; i++){
            t+=nums[i];
            sum.push_back(make_pair(i, t));
        }
        
        sort(sum.begin(), sum.end(), pair_cmp);
        diff = sum[1].second - sum[0].second;
        for(int i = 1; i <= sz; i++){
            long long delta = sum[i].second - sum[i-1].second;
            if(delta <= diff){
                diff = delta;
                res[0] = min(sum[i].first, sum[i-1].first) + 1;
                res[1] = max(sum[i].first, sum[i-1].first);
            }
        }
        return res;
    }
};
