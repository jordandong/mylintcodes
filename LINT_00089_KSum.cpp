/*
Given n distinct positive integers, integer k (k <= n) and a number target.

Find k numbers where sum is target. Calculate how many solutions there are?

Example:
Given [1,2,3,4], k=2, target=5.

There are 2 solutions:
[1,4] and [2,3], return 2.
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int sz = A.size();
        if(k > sz)
            return 0;

        int dp[k+1][sz+1][target+1]; //how many ways to select k nums in the first sz elements with target
        memset(dp, 0, sizeof(int)*(k+1)*(sz+1)*(target+1));
        
        for (int i=1;i<=sz;i++)
            if (A[i-1]<=target){
                for (int j=i; j<=sz; j++)
                    dp[1][j][A[i-1]] = 1;
        }

        for (int i = 2; i <= k; i++){
            for (int j = i; j <= sz; j++){
                for (int val = 1; val <= target; val++){
                    dp[i][j][val] = 0;
                    
                    if(j > i) //ignore A[j-1]
                        dp[i][j][val] += dp[i][j-1][val];

                    if(val >= A[j-1]) //choose A[j-1]
                        dp[i][j][val] += dp[i-1][j-1][val-A[j-1]];
                }
            }
        }
        return dp[k][sz][target];
    }
};

#if 0
//Cannot pass large input UT
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int res = 0;
        if(k > A.size() || k==0)
            return res;

        sort(A.begin(), A.end());
        kSumHelper(A, 0, k, target, res);
        return res;
    }
    
    void kSumHelper(vector<int> &A, int start, int k, int target, int &res){
        if(k == 0 ){
            if(target == 0)
                res++;
            return;
        }
        
        for(int i = start; i < A.size() - k +1; i++){
            if(A[i] > target)
                return;
            kSumHelper(A, i+1, k-1, target - A[i], res);
        }
    }
};
#endif
