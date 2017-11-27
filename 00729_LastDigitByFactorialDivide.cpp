/*
We are given two numbers A and B such that B >= A.
We need to compute the last digit of this resulting F such that F = B! / A! where 1 <= A, B <= 10^18 (A and B are very large)

Example
Given A = 2, B = 4, return 2
A! = 2 and B! = 24, F = 24 / 2 = 12 --> last digit = 2

Given A = 107, B = 109, return 2

Tags 
Mathematics Google
*/

class Solution {
public:
    /*
     * @param : the given number
     * @param : another number
     * @return: the last digit of B! / A! 
     */
    int computeLastDigit(long long A, long long B) {
        // write your code here
        //B! / A! = B*(B - 1)*..*(B - B + A + 1)* A! / A!  
        int ans = 1;
        for (long long v = B; v > A; v--) {
            long long d = v % 10;
            ans *= d;
            ans %= 10;
            if (!ans)
                return ans;
        }
        return ans;
    }
};
