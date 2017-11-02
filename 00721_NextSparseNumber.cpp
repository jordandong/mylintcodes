/*
A number is Sparse if there are no two adjacent 1s in its binary representation. Given a number n, find the smallest Sparse number which greater than or equal to n.
eg. 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.

Example
Given n = 6, return 8
Next Sparse Number is 8

Given n = 4, return 4
Next Sparse Number is 4

Given n = 38, return 40
Next Sparse Number is 40

Given n = 44, return 64
Next Sparse Number is 64

Tags 
Bit Manipulation Facebook
*/

class Solution {
public:
    /*
     * @param : a number
     * @return: return the next sparse number behind x
     */
    int nextSparseNum(int x) {
        // write your code here
        int base = 0x3, clear = 0xFFFFFFFF;
        for (int rot = 0; rot < 31; rot++) {
            int mask = (base << rot);
            if ((x & mask) == mask) {
                x &= (clear << rot);
                x += (0x1 << rot);
            }
        }
        return x;
    }
};
