/*
Check a positive number is a palindrome or not.

A palindrome number is that if you reverse the whole number you will get exactly the same number.

Notice
It's guaranteed the input number is a 32-bit integer, but after reversion, the number may exceed the 32-bit integer.

Example
11, 121, 1, 12321 are palindrome numbers.
23, 32, 1232 are not palindrome numbers.

Tags 
String Integer
*/

class Solution {
public:
    /**
     * @param num a positive number
     * @return true if it's a palindrome or false
     */
    bool palindromeNumber(int num) {
        // Write your code here
        int p = 0;
        int q = num;
        while(num != 0){
            p *= 10;
            p += (num % 10);
            num /= 10;
        }
        return p==q && q>=0; //if overfow,  then non-equal
    }
};

class Solution {
public:
    /**
     * @param num a positive number
     * @return true if it's a palindrome or false
     */
    bool palindromeNumber(int num) {
        // Write your code here
        if (num < 0)
            return false;
        int d = 1;
        while (num / d >= 10) //find the highest digit
            d *= 10;
        while (num != 0){
            if (num / d != num % 10)
                return false;
            num = (num % d) / 10;//remove both the highest and lowest digits
            d /= 100;
        }
        return true;
    }
};
