/*
Write a method anagram(s,t) to decide if two strings are anagrams or not.

Example
Given s="abcd", t="dcab", return true
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        int mp[256];
        memset(mp, 0, sizeof(int)*256);
        for(auto e : s){
            mp[e]++;
        }
        for(auto e : t){
            mp[e]--;
        }
        for(int i = 0; i < 256; i++){
            if(mp[i] != 0)
                return false;
        }
        return true;
    }
};
