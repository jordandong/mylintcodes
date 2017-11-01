/*
Write a function, give a string A consisting of N characters and a string B consisting of M characters, returns the number of times A must be stated such that B is a substring of the repeated string. If B can never be a substring of the repeated A, then your function should return -1.

 Notice

Assume that 0 <= N <= 1000, 1 <= M <= 1000

Example
Given A = abcd, B = cdabcdab

your function should return 3, bcause after stating string A three times we otain the string abcdabcdabcd. String B is a substring of this string.
*/

class Solution {
public:
    /*
     * @param : string A to be repeated
     * @param : string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        // write your code here
        int count = 1, a = 0, b = 0;
        
        for (int i = 0; i < A.length(); i++) {
            b = 0;
            if (A[i] != B[b])
                continue;
            a = i;
            while (b < B.length() && a < A.length() && A[a] == B[b]) {
                if (++b == B.length())
                    return count;
                if (++a == A.length()) {
                    a = 0;
                    count++;
                }
            }
        }
        return -1;
    }
};
