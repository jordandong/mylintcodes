/*
Implement an algorithm to determine if a string has all unique characters

Example
Given "abc", return true

Given "aab", return false

Challenge
What if you can not use additional data structures?
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        int m[256];
        memset(m, 0, sizeof(int)*256);
        
        for(char c : str){
            m[c]++;
            if(m[c]>1)
                return false;
        }
        return true;
    }
};
