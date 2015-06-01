/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.

Have you met this question in a real interview? Yes

Example
Given s = "Hello World", return 5.

Note
A word is defined as a character sequence consists of non-space characters only.

Tags Expand 
String
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int N = s.length();
        int end = N - 1;
        while (end >= 0 && s[end] == ' ')
            end--;
        int start = end;
        while (start >= 0 && s[start] != ' ')
            start--;
        return end - start;
    }
};
