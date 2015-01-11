/*
Given a list of numbers that may has duplicate numbers, return all possible subsets

Note:
Each element in a subset must be in non-descending order.
The ordering between two subsets is free.
The solution set must not contain duplicate subsets.

Example:
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // write your code here
        int sz = S.size();
        vector<vector<int> > res;
        int last_n = 0;
        int cur_n = 0;
        
        res.push_back(vector<int>());
        
        sort(S.begin(), S.end());
        for(int i = 0; i < sz ; i++){
            cur_n = res.size();
            int j = 0;
            if(i > 0 && S[i] == S[i-1]){
                j = last_n; //Avoild Dup, only apply dup element to the new added solutions
            }
            last_n = cur_n;
            for(; j < cur_n; j++){
                vector<int> tmp = res[j];
                tmp.push_back(S[i]);
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};
