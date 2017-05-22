/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Example,
1. The length of both num1 and num2 is < 110.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

Tags 
Mathematics String Facebook Twitter
*/

class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return product of num1 and num2
     */
    string multiply(string& num1, string& num2) {
        // Write your code here
        int n1 = num1.size();
        int n2 = num2.size();
        int n3 = n1 + n2;
        int num3[n3];
        memset(num3, 0, sizeof(int)*n3);

        for(int i = n1 - 1; i >= 0; i--){
            int carry = 0;
            int j;
            for(j = n2 - 1; j >= 0; j--){
                int t = carry + num3[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
                num3[i + j + 1] = t % 10;
                carry = t / 10;
            }
            num3[i + j + 1] = carry;
        }

        string res = "";
        int i = 0;
        while (i < n3 - 1 && num3[i] == 0) // skip leading zeros except the one in one's
            i++;
        while (i < n3)
            res.push_back('0' + num3[i++]);
        return res;
    }
};
