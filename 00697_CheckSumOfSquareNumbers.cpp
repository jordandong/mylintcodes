/*
Given a integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Example
Given n = 5
Return true // 1 * 1 + 2 * 2 = 5

Given n = -5
Return false

Tags 
Mathematics Enumeration
*/

class Solution {
public:
    /*
     * @param : the given number
     * @return: whether whether there're two integers
     */
    bool checkSumOfSquareNumbers(int num) {
        // write your code here
        if (num < 0)
            return false;
        for (long long a = 0; a * a * 2 <= num; a++) {
            long long b2 = num - a * a;
            int b = sqrt(b2);
            if (b * b == b2)
                return true;
        }
        return false;
    }
};
