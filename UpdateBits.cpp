/*
Given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e g , M becomes a substring of N located at i and starting at j)   

Example:
Given N = (10000000000)2, M = (10101)2, i = 2, j = 6
return N = (10001010100)2

Challenge:
Minimum number of operations？

Tags Expand 
Cracking The Coding Interview Bit Manipulation Binary Representation
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        i = i < 0  ? 0  : i;
        i = i > 31 ? 31 : i;
        j = j < 0  ? 0  : j;
        j = j > 31 ? 31 : j;
        if(i > j)
            swap(i, j);
        
        int mask1;
        if(j == 31)
            mask1 = ~0;
        else
            mask1 = (1<<(j + 1)) - 1;//depends on machine if left shift more then 31
        int mask2 = ((1<<i) - 1);
        int mask = ~(mask1 ^ mask2);
        n = n & mask;
        return n | (m<<i);
    }
};
