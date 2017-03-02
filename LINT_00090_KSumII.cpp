/*
Given n unique integers, number k (1<=k<=n)  and target. Find all possible k integers where their sum is target.

Example:
Given [1,2,3,4], k=2, target=5, [1,4] and [2,3] are possible solutions.
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> sol;
        if(k > A.size() || k==0)
            return res;

        sort(A.begin(), A.end());
        kSumIIHelper(A, 0, k, target, sol, res);
        return res;
    
    }
    
    void kSumIIHelper(vector<int> &A, int start, int k, int target, vector<int> &sol, vector<vector<int> > &res){
        if(k == 0 ){
            if(target == 0)
                res.push_back(sol);
            return;
        }
        
        for(int i = start; i < A.size() - k +1; i++){
            if(A[i] > target)
                return;
            sol.push_back(A[i]);
            kSumIIHelper(A, i+1, k-1, target - A[i], sol, res);
            sol.pop_back();
        }
    }
};
