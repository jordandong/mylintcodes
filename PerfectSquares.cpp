/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example
Given n = 12, return 3 because 12 = 4 + 4 + 4
Given n = 13, return 2 because 13 = 4 + 9

Tags
Dynamic Programming Mathematics Breadth First Search
*/
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector<int> mi(n + 1, INT_MAX);
        mi[0] = 0;  
        for(int i = 1; i <= n; i++)
            for(int j = 1; j * j <= i; j++)
                if(mi[i] >= mi[i - j * j] + 1)
                    mi[i] = mi[i - j * j] + 1;
        return mi[n];
    }
};
