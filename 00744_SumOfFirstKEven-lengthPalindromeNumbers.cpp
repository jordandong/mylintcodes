/*
Given a integer k, find the sum of first k even-length palindrome numbers.
Even length here refers to the number of digits of a number is even.

Example
Given k = 3, return 66 // 11 + 22 + 33 = 66 (Sum of first three even-length palindrome 
numbers)

Given k = 10, return 1496
// 11 + 22 + 33 + 44 + 55 + 66 + 77 + 88 + 99 + 1001 = 1496

Tags 
Enumeration Mathematics Facebook
*/

class Solution {
public:
    /**
     * @param k: 
     * @return: the sum of first k even-length palindrome numbers
     */
    int sumKEven(int k) {
        // Write your code here
        int base = 10, start = 1, sum = 0;
        while (k--) {
            sum += (start * base + reverseNum(start));
            if (++start >= base)
                base *= 10;
        }
        return sum;
    }
private:
    int reverseNum(int num) {
        int res = 0;
        while (num) {
            res *= 10;
            res += (num % 10);
            num /= 10;
        }
        return res;
    }
};
