/*
Implement pow(x, n).

Have you met this question in a real interview? Yes

Example
Pow(2.1, 3) = 9.261
Pow(0, 1) = 0
Pow(1, 0) = 1

Note
You don't need to care about the precision of your answer, it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.

Challenge
O(logn) time

Tags Expand 
Binary Search LinkedIn Divide and Conquer Mathematics Facebook
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        double res = 1;
        bool neg = false;
        if (n < 0) {
            neg = true;
            n = -n;
        }
        while (n) {
            if (n & 0x1)
                res *= x;
            n >>= 1;
            x *= x;
        }
        return neg ? 1/res : res;
    }
};
