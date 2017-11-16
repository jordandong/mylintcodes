/*
Given a number n, we need to find the sum of all the elements from all possible subsets of a set formed by first n natural numbers.

Example
Given n = 2, return 6
Possible subsets are {{1}, {2}, {1, 2}}. Sum of elements in subsets
is 1 + 2 + 1 + 2 = 6

Given n = 3, return 24
Possible subsets are {{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
Sum of subsets is : 
1 + 2 + 3 + (1 + 2) + (1 + 3) + 
(2 + 3) + (1 + 2 + 3)
Tags 
Mathematics Bloomberg
*/

class Solution {
public:
    /*
     * @param : the given number
     * @return: Sum of elements in subsets
     */
    int subSum(int n) {
        // write your code here
        long long sum = (1 + n) * n / 2;
        return sum * pow(2, n - 1);
    }
};
