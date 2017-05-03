/*
Given two strings S and T, determine if they are both one edit distance apart.

Example
Given s = "aDb", t = "adb"
return true

Tags 
String Twitter Uber Snapchat Facebook
*/

class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string& s, string& t) {
        // Write your code here
        int M = s.length();
        int N = t.length();
        if(M > N)
            return isOneEditDistance(t, s);
        if(N - M > 1)
            return false;
        int i = 0;
        int j = 0;
        while(i < M && s[i] == t[j]){
            i++;
            j++;
        }

        if(i == M)
            return M != N;

        j++;
        if(M == N)
            i++;
  
        while(i < M && s[i] == t[j]){
            i++;
            j++;
        }
        return i == M;
    }
};
