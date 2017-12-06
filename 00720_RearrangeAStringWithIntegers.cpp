/*
Given a string containing uppercase alphabets and integer digits (from 0 to 9), write a function to return the alphabets in the order followed by the sum of digits.

Example
Given str = AC2BEW3, return ABCEW5
Alphabets in the lexicographic order, followed by the sum of integers(2 and 3).

Tags 
Facebook
*/

class Solution {
public:
    /*
     * @param str: a string containing uppercase alphabets and integer digits
     * @return: the alphabets in the order followed by the sum of digits
     */
    string rearrange(string &str) {
        // Write your code here
        sort(str.begin(), str.end());
        int sum = 0, i = 0;
        for (i = 0; i < str.length(); i++) {
            if ('0' <= str[i] && str[i] <= '9')
                sum += (str[i] - '0');
            else
                break;
        }
        
        return str.substr(i) + (i > 0 ? to_string(sum) : "");
    }
};
