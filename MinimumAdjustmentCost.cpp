/*
Given an integer array, adjust each integers so that the difference of every adjcent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]| 

Note:
You can assume each number in the array is a positive integer and not greater than 100

Example:
Given [1,4,2,3] and target=1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal. Return 2.
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int sz = A.size();
        int range = 100;
        int mi = INT_MAX;
        int dp[sz][range + target + 1]; 
        // dp[i][j] means the mini cost when the last element at index i was adjusted to j
        memset(dp, 0, sizeof(int)*sz*(range+target+1));
        for(int v=0; v <= (range + target); v++){
            dp[0][v] = abs(v - A[0]);
        }
        
        for(int i = 1; i < sz; i++){
            for(int v = 0; v <= (range + target); v++){
                dp[i][v] = INT_MAX;
                for(int k = max(0, v-target); k <= min(range+target, v+target); k++){
                    dp[i][v] = min(dp[i][v], dp[i-1][k] + abs(A[i]-v));
                }
                
                if(i == sz-1){
                    mi = min(mi, dp[i][v]);
                }
            }
        }
        return mi;
    }
};
