/*
Given a string, find the length of the longest substring without repeating characters.

Example
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.

Challenge
O(n) time

Tags Expand 
String Two Pointers Hash Table
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        bool mp[256];
        int b = 0, e = 0;
        int res = 0;
        memset(mp, 0, sizeof(mp));
        
        while(e < s.length()){
            while (mp[s[e]])
                mp[s[b++]] = false;
            mp[s[e++]] = true;
            res = max(res, e - b);
        }
        return res;
    }
};
