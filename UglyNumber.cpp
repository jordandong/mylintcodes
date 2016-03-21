/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Notice:
Note that 1 is typically treated as an ugly number.

Example:
Given num = 8 return true
Given num = 14 return false

Tags
Mathematics
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if (num == 0)
            return false;
        int base = 2;
        while (num % base == 0)
            num /= base;
        base = 3;
        while (num % base == 0)
            num /= base;
        base = 5;
        while (num % base == 0)
            num /= base;
        return num == 1;
    }
};
