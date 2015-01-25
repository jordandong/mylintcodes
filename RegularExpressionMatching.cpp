/*
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Example:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if(*p == '\0')
            return *s == '\0';

        if(*(p+1) != '*'){
            if((*p == '.' && *s != '\0') || *p == *s){
                return isMatch(s+1, p+1);
            }else{
                return false;
            }
        }else{
            while((*p == '.' && *s != '\0') || *p == *s){
                if(isMatch(s, p+2))//match zero *
                    return true;
                s++;//match one more *
            }
            return isMatch(s, p+2); //finish match *
        }
    }
};
