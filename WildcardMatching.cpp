/*
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Example
Some examples:

isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
Tags Expand 
String Greedy LeetCode Dynamic Programming Backtracking
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if(!s || !p)
            return s == p;
        const char *star = NULL;
        const char *pos_s = s;
        while(*s){
            if(*p == '*'){
                star = p++;
                pos_s = s;
            }else if(*p != '?' && *p != *s){
                if(!star){
                    return false;
                }else{
                    p = star + 1;
                    s = ++pos_s;
                }
            }else{
                p++;
                s++;
            }
        }
        while(*p == '*')
            p++;
        return *p == *s;
    }
};
