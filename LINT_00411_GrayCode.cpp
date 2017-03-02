/*
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, find the sequence of gray code. A gray code sequence must begin with 0 and with cover all 2n integers.

Example
Given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2

Note
For a given n, a gray code sequence is not uniquely defined.
[0,2,3,1] is also a valid gray code sequence according to the above definition.

Challenge
O(2^n) time.

Tags Expand 
Binary Recursion
*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        int num = 1 << n;
        //x          1110001100  1 0 00000
        //x/2        0111000110  0 1 00000
        //(x - 1)    1110001100  0 1 11111
        //(x - 1)/2  0111000110  0 0 11111
        for(int i = 0; i < num; i++)
            res.push_back((i >> 1) ^ i);
        return res;
    }
};
