/*
Given a string, count number of subsequences of the form a^i b^j c^ k,
i.e., it consists of i a characters, followed by j b characters, followed by k c characters where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.

Example
Given s = abbc, return 3
Subsequences are abc, abc and abbc

Given s = abcabc, return 7
Subsequences are abc, abc, abbc, aabc, abcc, abc and abc

Tags 
Mathematics Amazon
*/

class Solution {
public:
    /*
     * @param : the input string
     * @return: the number of subsequences 
     */
    int countSubsequences(string &source) {
        // write your code here
        int n = source.length();
        int sa = 0, sb = 0, sc = 0;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == 'c') {
                sc = sc + sc + 1; //start with c = using current c + not using current c
            } else if (source[i] == 'b') {
                sb = sc + sb + sb;
            } else {
                sa = sb + sa + sa;
            }
        }
        return sa;
    }
};
