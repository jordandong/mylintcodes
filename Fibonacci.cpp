/*
Find the Nth number in Fibonacci sequence.

A Fibonacci sequence is defined as follow:
The first two numbers are 0 and 1.
The i th number is the sum of i-1 th number and i-2 th number.
The first ten numbers in Fibonacci sequence is:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

Example
Given 1, return 0
Given 2, return 1
Given 10, return 34

Note
The Nth fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.

Tags Expand 
Enumeration Mathematics Non Recursion
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int a = 0;
        int b = 1;
        if (n <= 0)
            return a;
        if (n == 2)
            return b;
        while (n > 2) {
            a = a + b;
            swap(a, b);
            n--;
        }
        return b;
    }
};
