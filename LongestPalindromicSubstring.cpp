/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
Have you met this question in a real interview? Yes

Example
Given the string = "abcdzdcab", return "cdzdc".

Challenge
O(n^2) time is acceptable. Can you do it in O(n) time.

Tags Expand 
String
*/

//S:O(N^2) T:O(N^2)
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        int N = s.length();
        int mx = 1;
        int start = 0;
        bool dp[N][N];
        memset(dp, 0, sizeof(dp));
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i; j < N; j++) {
                if(i == j){
                    dp[i][j] = true;
                }else if(s[i] == s[j] && (i + 1 == j || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(j - i + 1 > mx){
                        mx = j - i + 1;
                        start = i;
                    }
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(start, mx);
    }
};
