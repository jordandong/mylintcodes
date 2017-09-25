/*
Given a non-negative integer n, print the number in words.

 Notice

n <= 2147483647

Have you met this question in a real interview? Yes
Example
Given n = 125

Return one hundred twenty five

Tags 
Enumeration

*/

class Solution {
public:
    /*
     * @param : the number
     * @return: the number in words
     */
    string convertWords(int number) {
        // Write your code here
        if (number == 0)
            return "zero";
        string res = "";
        string mp[4] = {" billion", " million", " thousand", ""};
        int base = 1000000000;
        int idx = 0;
        while (base) {
            int digits = number / base;
            if (digits) {
                res += numberToWordsHelper(digits);
                res += mp[idx];
                number %= base;
            }
            base /= 1000;
            idx++;
        }
        return res.substr(1);
    }
    
    string numberToWordsHelper(int num) {
        string res = "";
        int base = 100;
        string mp_ones[10] = {" zero", " one", " two", " three", " four",
                                " five", " six", " seven", " eight", " nine"};
        string mp_ten[10] = {" ten", " eleven", " twelve", " thirteen", " fourteen",
                                " fifteen", " sixteen", " seventeen", " eighteen", " nineteen"};
        string mp_tens[10] = {"NA", "NA", " twenty", " thirty", " forty",
                                " fifty", " sixty", " seventy", " eighty", " ninety"};
        while (base) {
            int digits = num / base;
            if (digits) {
                if (base == 100) {
                    res += mp_ones[digits];
                    res += " hundred";
                } else if (base == 10) {
                    if (digits == 1) {
                        res += mp_ten[num % 10];
                        base /= 10;
                    } else {
                        res += mp_tens[digits];
                    }
                } else {
                    res += mp_ones[digits];
                }
                num %= base;
            }
            base /= 10;
        }
        return res;
    }
};
