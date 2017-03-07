/*
Implement int sqrt(int x).
Compute and return the square root of x.

Example:
sqrt(3) = 1
sqrt(4) = 2
sqrt(5) = 2
sqrt(10) = 3

Challenge : O(log(x))
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long long lo = 0;
        long long hi = x/2;
        
        while(lo + 1 < hi){
            long long mid = lo + (hi - lo)/2;
            long long p = mid*mid;
            if(p == x)
                return mid;
            if(p > x)
                hi = mid;
            else
                lo = mid;
        }
        return lo;
    }
};
