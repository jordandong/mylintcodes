/*
We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1. We need to find minimum positive number x such that:

     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 

Example
Given  nums = [3, 4, 5], rems = [2, 3, 1], return 11
11 is the smallest number such that:
- When we divide it by 3, we get remainder 2. 
- When we divide it by 4, we get remainder 3.
- When we divide it by 5, we get remainder 1. 

Tags 
Mathematics
*/

class Solution {
public:
    /*
     * @param num: the given array
     * @param rem: another given array
     * @return: The minimum positive number of conditions to meet the conditions
     */
    int remainderTheorem(vector<int> &num, vector<int> &rem) {
        // write your code here
        // Compute product of all numbers
        if (num.size() != rem.size())
            return -1;
        long long prod = 1.0; 
        int k = num.size();
        for (int i = 0; i < k; i++)
            prod *= num[i];
        // Initialize result
        long long result = 0;
        // Apply above formula
        for (int i = 0; i < k; i++) {
            long long pp = prod / num[i];
            result += rem[i] * inv(pp, num[i]) * pp;
        }
        return result % prod;
    }
private:
    // Returns modulo inverse of a with respect to m using extended
    // Euclid Algorithm. Refer below post for details:
    // http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
    int inv (long long a, int m) {
        int m0 = m, t, q;
        int x0 = 0, x1 = 1;
 
        if (m == 1)
            return 0;
        // Apply extended Euclid Algorithm
        while (a > 1) {
            // q is quotient
            q = a / m;
            t = m;
            // m is remainder now, process same as
            // euclid's algo
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        // Make x1 positive
        if (x1 < 0)
            x1 += m0;
        return x1;
    }
};
