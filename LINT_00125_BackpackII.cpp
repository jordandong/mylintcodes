/*
Given n items with size A[i] and value V[i], and a backpack with size m. What's the maximum value can you put into the backpack?
Note
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int sz = A.size();
        int dp[m+1];
        memset(dp, 0, sizeof(int)*(m+1));
        for(int i=0; i<sz; i++){
            for(int j=m; j>=A[i]; j--){
                if(dp[j-A[i]] + V[i] > dp[j]){
                    dp[j] = dp[j-A[i]] + V[i];
                }
            }
        }
        return dp[m];
    }
};
