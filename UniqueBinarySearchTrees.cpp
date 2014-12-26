/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
Example
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        int dp[n+1];
        memset(dp, 0, (n+1)*sizeof(int));
        dp[0]=1;
        return nTHelper(n, dp);
        
    }
    
    int nTHelper(int n, int* dp){
        if(dp[n]!=0)
            return dp[n];
        for(int i=1; i<=n; i++){
            dp[n]+=nTHelper(i-1, dp)*nTHelper(n-i, dp);
        }
        return dp[n];
    }
};
