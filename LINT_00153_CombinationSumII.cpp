/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example:
For example, given candidate set 10,1,6,7,2,1,5 and target 8,

A solution set is: 
[1,7]
[1,2,5]
[2,6]
[1,1,6]
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> sol;
        sort(num.begin(), num.end());
        combinationSum2Helper(num, target, 0, sol, res);
        return res;
    }
    
    void combinationSum2Helper(vector<int> &num, int target, int start, vector<int> &sol, vector<vector<int> > &res){
        if(start == num.size() || target == 0){
            if(target == 0)
                res.push_back(sol);
            return;
        }
        
        for(int i = start; i<num.size(); i++){
            if(num[i] > target)
                return;
            if(i>start && num[i] == num[i-1])
                continue;    
            sol.push_back(num[i]);
            combinationSum2Helper(num, target - num[i], i + 1, sol, res);
            sol.pop_back();
        }
    }
};
