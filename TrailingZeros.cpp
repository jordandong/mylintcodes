/*
Write an algorithm which computes the number of trailing zeros in n factorial.

Example
11! = 39916800, so the out should be 2

Challenge
O(log N) time
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        double x = 1;
        long long base = (long long)pow(5, x);
        long long res = 0;
        while(base <= n){
            res += n/base;
            base = (long long)pow(5, ++x);
        }
        return res;
    }
};
