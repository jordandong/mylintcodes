/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Notice
Note: N is an integer in the range [0, 10^9].

Example
Given N = 10, return 9
Given N = 12345, return 12345
Given N = 10000, return 9999

Tags 
Greedy
*/

class Solution {
public:
    /**
     * @param num: a non-negative integer N
     * @return: the largest number that is less than or equal to N with monotone increasing digits.
     */
    int monotoneDigits(int num) {
        // write your code here
        string s = to_string(num);
        int n = s.length();
        int most_left = n;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[i + 1]) {
                s[i] -= 1;
                most_left = i + 1;
            }
        }
        while (most_left < n)
            s[most_left++] = '9';
        return stoi(s);
    }
};
