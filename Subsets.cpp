/*
Given a set of distinct integers, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Example:
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	int n = nums.size();
    	int mx = 1<<n;
    	vector<vector<int> > res;

    	for(int i = 0; i < mx; i++){
    	    vector<int> sol;
    	    for(int shift = 0; shift < n; shift++){
    	        if((i>>shift) & 0x00000001){
    	            sol.push_back(nums[shift]);
    	        }
    	    }
    	    res.push_back(sol);
    	}
    	return res;
    }
};
