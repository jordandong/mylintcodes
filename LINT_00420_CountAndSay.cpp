/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.
Have you met this question in a real interview? Yes

Example
Given n = 5, return "111221".

Note
The sequence of integers will be represented as a string.

Tags Expand 
String
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if (n < 1)
            return "";
        string res("1");
        while (n > 1) {
            string tmp = "";
            int i = 0;
            while (i < res.size()) {
                int j = i;
                while (j < res.size() && res[j] == res[i])
                    j++;
                tmp.push_back('0' + (j - i));
                tmp.push_back(res[i]);
                i = j;
            }
            res = tmp;
            n--;
        }
        return res;
    }
};
