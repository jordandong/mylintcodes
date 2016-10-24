/*
Determine the number of bits required to convert integer A to integer B 

Example:
Given n = 31, m = 14,return 2
(31)10=(11111)2
(14)10=(01110)2

Tags Expand 
Cracking The Coding Interview Bit Manipulation Binary Representation
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int d = a ^ b;
        int res = 0;
        while(d){
            res++;
            d = d & (d - 1);
        }
        return res;
    }
};
