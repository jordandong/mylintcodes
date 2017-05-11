/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Notice
1. The length of both num1 and num2 is < 5100.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example
Given num1 = "123", num2 = "45"
return "168"

Tags 
Mathematics Airbnb Google
*/

class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    string addStrings(string& num1, string& num2) {
        // Write your code here
        int n1 = num1.length(), n2 = num2.length();
        string res = "";
        int carry = 0;
        while (n1 > 0 && n2 > 0) {
            int v = num1[--n1] - '0' + num2[--n2] - '0' + carry;
            carry = v / 10;
            v %= 10;
            res.push_back('0' + v);
        }
        while (n1 > 0) {
            int v = num1[--n1] - '0' + carry;
            carry = v / 10;
            v %= 10;
            res.push_back('0' + v);
        }
        while (n2 > 0) {
            int v = num2[--n2] - '0' + carry;
            carry = v / 10;
            v %= 10;
            res.push_back('0' + v);
        }
        if (carry) {
            res.push_back('0' + carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
