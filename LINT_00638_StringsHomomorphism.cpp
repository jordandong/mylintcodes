／*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

Notice
You may assume both s and t have the same length.

Example
Given s = "egg", t = "add", return true.
Given s = "foo", t = "bar", return false.
Given s = "paper", t = "title", return true.

Tags 
Hash Table LinkedIn
*/

class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s
     * can be replaced to get t or false
     */
    bool isIsomorphic(string& s, string& t) {
        // Write your code here
        char mp1[256];
        char mp2[256];
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        if(s.length() != t.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(mp1[s[i]] != 0 && mp1[s[i]] != t[i])
                return false;
            if(mp2[t[i]] != 0 && mp2[t[i]] != s[i])
                return false;
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};
