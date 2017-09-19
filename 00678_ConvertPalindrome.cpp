/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.

Example
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
*/

class Solution {
public:
    /*
     * @param : String
     * @return: String
     */
    string convertPalindrome(string str) {
        // Write your code here
        int i = 0, j = str.length() - 1;
        while (j >= 0) {
            if (str[i] == str[j])
                i++;
            j--;
        }

        if (i == str.length())
            return str;

        string suffix = str.substr(i);
        string r_suffix = suffix;
        reverse(r_suffix.begin(), r_suffix.end());
        return r_suffix + convertPalindrome(str.substr(0, i)) + suffix;
    }
};
