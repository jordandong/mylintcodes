/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

For example, given candidate set 2,3,6,7 and target 7, 

A solution set is: 
[7] 
[2, 2, 3] 

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Example:
given candidate set 2,3,6,7 and target 7, 

A solution set is: 
[7] 
[2, 2, 3]
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> sol;
        combinationSumHelper(0, candidates, target, sol, res);
        return res;
    }
    
    void combinationSumHelper(int start, vector<int> &candidates, int target,
                              vector<int> &sol, vector<vector<int> > &res){
        if(target == 0){
            res.push_back(sol);
            return;
        }
        
        for(int i = start; i<candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                return;
            sol.push_back(candidates[i]);
            combinationSumHelper(i, candidates, target - candidates[i], sol, res);
            sol.pop_back();
        }
    }
};
