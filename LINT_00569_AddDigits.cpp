/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example
Given num = 38.
The process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return 2.

Challenge 
Could you do it without any loop/recursion in O(1) runtime?
Wikipedia article useful. https://en.wikipedia.org/wiki/Digital_root

Tags 
Mathematics
*/
 
class Solution {
public:
    /**
     * @param num a non-negative integer
     * @return one digit
     */
    int addDigits(int num) {
        // Write your code here
        int val = num;
        while (num >= 10) {
            num = 0;
            while (val) {
                num += val % 10;
                val /= 10;
            }
            val = num;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
