/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int a = 0;
        int b = 1;
        int c = 0;
        for(int i=1; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
