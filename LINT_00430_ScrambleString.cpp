/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Have you met this question in a real interview? Yes

Example
Challenge
O(n^3) time

Tags Expand 
String Dynamic Programming
*/

class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        int M = s1.length();
        int N = s2.length();
        if(M != N)
            return false;
        //200+ ms
        //vector<vector<vector<bool> > > dp(N, vector<vector<bool> >(N, vector<bool>(N + 1, false)));
        
        //62ms
         bool ***dp = new bool**[N];
         memset(dp, 0, sizeof(bool)*N);
         for (int i1 = 0; i1 < N; i1++) {
             dp[i1] = new bool*[N];
             memset(dp[i1], 0, sizeof(bool)*N);
             for (int i2 = 0; i2 < N; i2++) {
                 dp[i1][i2] = new bool[N + 1];
                 memset(dp[i1][i2], 0, sizeof(bool)*(N + 1));
             }
         }
        //dp[i][j][l] means in s1 start at i, in s2 start at j, length is l are scramlbe
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N-  1; j >= 0; j--) {
                for (int l = 1; l <= N - max(i, j); l++) {
                    if(s1.substr(i, l) == s2.substr(j, l)){//string equal
                        dp[i][j][l] = true;
                    }else{
                        for (int k = 1; k < l; k++) {
                            if( (dp[i][j][k] && dp[i + k][j + k][l - k]) || 
                                (dp[i][j + l - k][k] && dp[i + k][j][l - k])) {
                                dp[i][j][l] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][N];
    }
};
