/*
Given a roman numeral, convert it to an integer.
The answer is guaranteed to be within the range from 1 to 3999.
Have you met this question in a real interview? Yes

Example
IV -> 4
XII -> 13
XXI -> 21
XCIX -> 99

Clarification:
What is Roman Numeral?
https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
http://baike.baidu.com/view/42061.htm

Tags Expand 
String
*/

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        int mp[26];
        mp['I' - 'A'] = 1;
        mp['V' - 'A'] = 5;
        mp['X' - 'A'] = 10;
        mp['L' - 'A'] = 50;
        mp['C' - 'A'] = 100;
        mp['D' - 'A'] = 500;
        mp['M' - 'A'] = 1000;
        int res = 0;
        int i = 0;
        for (i = 0; i < s.length() - 1; i++) {
            if(mp[s[i] - 'A'] < mp[s[i + 1] - 'A'])
                res -= mp[s[i] - 'A'];
            else
                res += mp[s[i] - 'A'];
        }
        res += mp[s[i] - 'A'];
        return res;
    }
};
