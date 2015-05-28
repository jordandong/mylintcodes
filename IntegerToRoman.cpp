/*
Given an integer, convert it to a roman numeral.
The number is guaranteed to be within the range from 1 to 3999.
Have you met this question in a real interview? Yes

Example
4 -> IV
13 -> XII
21 -> XXI
99 -> XCIX
more examples at: http://literacy.kent.edu/Minigrants/Cinci/romanchart.htm

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
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        string dict[4];
        int base = 1000;
        string res = "";
        
        while(n){
            switch(base){
                case 1:
                    dict[0] = "I";
                    dict[1] = "IV";
                    dict[2] = "V";
                    dict[3] = "IX";
                    break;
                case 10:
                    dict[0] = "X";
                    dict[1] = "XL";
                    dict[2] = "L";
                    dict[3] = "XC";
                    break;
                case 100:
                    dict[0] = "C";
                    dict[1] = "CD";
                    dict[2] = "D";
                    dict[3] = "CM";
                    break;
                case 1000:
                    dict[0] = "M";
                    break;
                default:
                    break;
            }    
            
            int d = n/base;
            while(d){
                if(d == 9){
                    res += dict[3];
                    d -= 9;
                }else if(d >= 5 ){
                    res += dict[2];
                    d -= 5;
                }else if(d == 4){
                    res += dict[1];
                    d -= 4;
                }else{
                    res += dict[0];
                    d -= 1;
                }
            }
            n = n % base;
            base /= 10;
        }
        return res;
    }
};
