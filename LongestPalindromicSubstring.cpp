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

//T:O(N) S:O(N)
//http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        string T = preProcess(s);
        int n = T.length();
        int P[n];
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++) {
            int i_mirror = 2*C - i; // equals to i' = C - (i-C)
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        
        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
    
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(string s) {
        int n = s.length();
        if (n == 0)
            return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);
        ret += "#$";
        return ret;
    }
};

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
