/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Have you met this question in a real interview? Yes

Example
Given encoded message 12, it could be decoded as AB (1 2) or L (12).
The number of ways decoding 12 is 2.

Tags
String Dynamic Programming
*/

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        int N = s.length();
        if(N == 0 || s[0] == '0')
            return 0;
            
        int dp[N + 1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 1; i < N; i++){
            if (s[i] != '0') //using single digit
                dp[i + 1] = dp[i];
            else
                dp[i + 1] = 0;
        
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) //using two digits
                dp[i + 1] += dp[i - 1];
        }
        return dp[N];
    }
};
