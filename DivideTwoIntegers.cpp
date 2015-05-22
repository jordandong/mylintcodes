/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return 2147483647

Example
Given dividend = 100 and divisor = 9, return 11.

Tags Expand 
High Precision
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        bool sign = false;
        unsigned int x, y;
        unsigned int res = 0;
        if(dividend < 0) {
            x = -dividend;
            sign = !sign;
        }else{
            x = dividend;
        }
        
        if (divisor < 0) {
            y = -divisor;
            sign = !sign;
        }else{
            y = divisor;
        }
        
        while (x >= y) {
            unsigned int shift = 0;
            unsigned int tmp = y;
            while( ( (unsigned long long)tmp << 1) <= x){
                tmp <<= 1; 
                shift++;
            }
            x -= tmp;
            res |= (1 << shift);
        }

        if(!sign && res > INT_MAX)
            return INT_MAX;
        else
            return sign ? -res : res;
    }
};
