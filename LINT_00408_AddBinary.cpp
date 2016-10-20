/*
Given two binary strings, return their sum (also a binary string).

Example
a = 11
b = 1
Return 100

Tags Expand 
String Binary
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string res;
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0) {
            int va = 0, vb = 0;
            if (i >= 0)
                va = a[i--] - '0';
            if (j >= 0)
                vb = b[j--] - '0';
            int v = va + vb + carry;
            carry = v/2;
            res.append(1, (char)(v%2 + '0'));
        }
        if (carry)
            res.append(1, (char)(carry + '0'));
        if (res.length() != 0)
            reverse(res.begin(), res.end());
        return res;
    }
};
