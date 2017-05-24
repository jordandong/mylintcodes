/*
Given an expression s includes numbers, letters and brackets.
Number represents the number of repetitions inside the brackets(can be a string or another expression).
Please expand expression to be a string.

Example
s = abc3[a] return abcaaa
s = 3[abc] return abcabcabc
s = 4[ac]dy, return acacacacdy
s = 3[2[ad]3[pf]]xyz, return adadpfpfpfadadpfpfpfadadpfpfpfxyz

Challenge 
Can you do it without recursion?

Tags 
Stack Recursion Divide and Conquer Non Recursion Yahoo
*/

class Solution {
public:
    /**
     * @param s  an expression includes numbers, letters and brackets
     * @return a string
     */
    string expressionExpand(string& s) {
        // Write your code here
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                num = 10 * num + s[i] - '0';
            } else if (s[i] == '[') {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            } else if (s[i] == ']') {
                string temp = strs.top();
                strs.pop();
                for (int k = 0; k < nums.top(); k++)
                    temp += res;
                nums.pop();
                res = temp;
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
