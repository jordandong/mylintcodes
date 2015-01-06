/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
For example,
If n = 4 and k = 2, a solution is:
[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > res;
        vector<int> tmp;
        if(k > n)
            return res;
        combineHelper(1, n, k, tmp, res);
        return res;
    }
    
    void combineHelper(int start, int end, int k, vector<int> &tmp, vector<vector<int> > &res){
        if(k == 0){
            res.push_back(tmp);
            return;
        }
        
        for(int i = start; i <= end; i++){
            tmp.push_back(i);
            combineHelper(i+1, end, k-1, tmp, res);
            tmp.pop_back();
        }
    }
};
