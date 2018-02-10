/*
Determines whether a binary representation of a non-negative integer n is a palindrome

Notice
0 <= n <= 2^32 - 1

Example
Given n = 0, return True
Explanation:
The binary representation of 0 is: 0

Given n = 3, return True
Explanation:
The binary representation of 3 is: 11

Given n = 4, return False
Explanation:
The binary representation of 4 is: 100

Given n = 6, return False
Explanation:
The binary representation of 6 is: 110
*/

class Solution {
public:
    /**
     * @param n: non-negative integer n
     * @return: return whether a binary representation of a non-negative integer n is a palindrome.
     */
    bool isPalindrome(int n) {
        // Write your code here
        long long d = 0;
        long long nn = n;
        while (nn) {
            d <<= 1;
            if (nn & 0x1)
                d |= 0x1;
            nn >>= 1;
        }
        return d == n;
    }
};
