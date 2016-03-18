/*
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Notice:
n and k are non-negative integers.

Example:
Given n=3, k=2 return 6

      post 1,   post 2, post 3
way1    0         0       1 
way2    0         1       0
way3    0         1       1
way4    1         0       0
way5    1         0       1
way6    1         1       0

Tags:
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n <= 0 || k <= 0)
            return 0;
        if (n <= 2)
            return pow(k, n);
        
        int same = k, diff = k*(k-1), res = k*k;
        for (int i = 3; i <= n; i++) {
            //at i, the num of last two same equal to the num of last two diff in previous step
            same = diff; 
            //at i, the num of last two different equal to the num of results in previous step multiply (k - 1)
            diff = res * (k - 1);
            res = same + diff;
        }
        return res;
    }
};
