/*
Validate if a given string is numeric.
Have you met this question in a real interview? Yes

Example
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Tags Expand 
String
*/

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int start = 0;
        int end = s.length() - 1;
        // trim leading spaces
        while (start <= end && s[start] == ' ')
            start++;

        if(start > end) //empty
            return false;

        //trim trailing spaces
        while(s[end] == ' ')
            end--;

        // skip leading +/-
        if (s[start]== '+' || s[start] == '-')
            start++;

        bool num = false; // is a digit
        bool dot = false; // is a '.'
        bool exp = false; // is a 'e'
        while(start <= end) {
            if (s[start] >= '0' && s[start] <= '9') {
                num = true;
            } else if (s[start] == '.') {
                if (exp || dot)
                    return false;
                dot = true;
            } else if (s[start] == 'e') {
                if(exp || num == false)
                    return false;
                exp = true; 
                num = false;
            } else if (s[start] == '+' || s[start] == '-') {
                if (s[start - 1] != 'e')
                    return false;
            } else {
                return false;
            }
            start++;
        }
        return num;
    }
};
