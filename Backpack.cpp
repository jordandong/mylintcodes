/*
Given n items with size A[i], an integer m denotes the size of a backpack. How full you can fill this backpack? 

Note
You can not divide any item into small pieces.

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select 2, 3 and 5, so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.

Tags Expand 
Dynamic Programming LintCode Copyright
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int mx = 0;
        int sz = A.size();
        bool dp[m + 1];
        memset(dp, 0, (m+1)*sizeof(bool));
        dp[0] = true;

        for(int i =0; i<sz; i++){
            for(int j = m; j>=A[i]; j--){
                dp[j] = dp[j-A[i]];
                if(dp[j])
                    mx = mx>j?mx:j;
            }
        }
        return mx;
    }
};
