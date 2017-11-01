/*
Given a string of numbers, write a function to find the maximum value from the string, you can add a + or * sign between any two numbers.

Example
Given str = 01231, return 10
((((0 + 1) + 2) * 3) + 1) = 10 we get the maximum value 10

Given str = 891, return 73
As 8 * 9 * 1 = 72 and 8 * 9 + 1 = 73 so 73 is maximum.
*/

class Solution {
public:
    /*
     * @param : the given string
     * @return: the maximum value
     */
    int calcMaxValue(string &str) {
        // write your code here
        int n = str.length();
        if (n == 0)
            return 0;
        int res = str[0] - '0';
        for (int i = 1; i < n; i++) {
            int d = (str[i] - '0');
            res = max(res + d, res * d);
        }
        return res;
    }
};
