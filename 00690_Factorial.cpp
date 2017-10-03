/*
Given a number n, return the factorial of the number as a string.

Example
Given a number n = 20
return 2432902008176640000
*/

class Solution {
public:
    /*
     * @param : an integer
     * @return:  the factorial of n
     */
    string factorial(int n) {
        // write your code here
        string res = "1";
        while (n) {
            res = multiply(res, to_string(n--));
        }
        return res;
    }

private:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int n3 = n1 + n2, i = 0;
        string num3(n3, '0');
        
        for(i = n1 - 1; i >= 0; i--){
            int carry = 0, j;
            for(j = n2 - 1; j >= 0; j--){
                int t = carry + (num3[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                num3[i + j + 1] = t % 10 + '0';
                carry = t / 10;
            }
            num3[i + j + 1] = carry + '0';
        }

        i = 0;
        while (i < n3 - 1 && num3[i] == '0') // skip leading zeros except the one in one's
            i++;
        return num3.substr(i);
    }
};
