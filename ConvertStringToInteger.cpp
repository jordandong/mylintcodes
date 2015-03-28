/*
Implement atoi to convert a string to an integer. If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Example
"10" =>10
"-1" => -1
"123123123123123" => 2147483647
"1.0" => 1

Tags Expand 
Basic Implementation String
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        int len = str.length();
        long long res = 0;
        if(len <= 0)
            return res;
        bool sign = false;
        int i = 0;
        while(i < len && str[i] == ' ')
            i++;
        while(i < len && str[len - 1] == ' ')
            len--;
        if(i < len && (str[i] == '-' || str[i] == '+')){
            sign = str[i++] == '-';
        }
        
        while(i < len){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }else{
                res *= 10;
                res += str[i] - '0';
                if(res > INT_MAX){
                    return sign ? INT_MIN : INT_MAX;
                }
            }
            i++;
        }
        return sign ? (int)res*(-1) : (int)res;
    }
};
