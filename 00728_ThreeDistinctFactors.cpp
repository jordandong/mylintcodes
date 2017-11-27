/*
Given a positive integer n (1 <= n <= 10^18).
Check whether a number has exactly three distinct factors, return true if it has exactly three distinct factors, otherwise false.

Example
Given n = 9, return true
Number 9 has exactly three factors: 1, 3, 9, so return true.

Given n = 10, return false

Tags 
Amazon Mathematics Microsoft
*/

class Solution {
public:
    /*
     * @param : the given number
     * @return:  return true if it has exactly three distinct factors, otherwise false
     */
    bool isThreeDisctFactors(long long n) {
        // write your code here
        // Find square root of number
        long long sq = sqrt(n);
        if (sq * sq != n)
            return false;
        return isPrime(sq) ? true : false;
    }
private:
    bool isPrime(long long n) {
        // Corner cases
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
            
        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n % 2 == 0 || n % 3 == 0)
            return false;
            
        for (long long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
};
