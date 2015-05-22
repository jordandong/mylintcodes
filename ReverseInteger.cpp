/*
Reverse digits of an integer. Returns 0 when the reversed integer overflows (signed 32-bit integer).

Example
Given x = 123, return 321
Given x = -123, return -321

Tags Expand 
Integer
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        bool neg = false;
        long long res = 0;
        long long y = n;
        if (y < 0) {
            neg = true;
            y = -y;
        }
        
        while (y) {
            res = 10*res + y%10;
            y /= 10;
            if (res > INT_MAX)
                return 0;
        }
        return neg ? -res:res;
    }
};
