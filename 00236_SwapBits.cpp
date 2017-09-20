/*
Write a program to swap odd and even bits in an integer with as few instructions as possible
(e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

Example
5 = (101)2 => (1010)2 = 10

Tags 
Bit Manipulation
*/

class Solution {
public:
    /*
     * @param x: An integer
     * @return: An integer
     */
    int swapOddEvenBits(int x) {
        // write your code here
        unsigned int mask_even = 0x55555555, mask_odd = 0xaaaaaaaa;
        return (((x & mask_even) << 1) | ((x & mask_odd) >> 1));
    }
};
