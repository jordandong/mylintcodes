/*
Write an algorithm to determine if a number is happy.

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Have you met this question in a real interview? Yes

Example
19 is a happy number
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

Tags Expand 
Hash Table Mathematics
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        unordered_map<int, bool> mp;
        int tmp = n;
        while (tmp && mp[tmp] == false) {
            if (tmp == 1)
                return true; 
            mp[tmp] = true;
            n = tmp;
            tmp = 0;
            while (n) {
                tmp += (n%10)*(n%10);
                n /= 10;
            }
        }
        return tmp == 1;
    }
};
