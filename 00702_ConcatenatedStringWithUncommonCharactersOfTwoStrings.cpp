/*
Two strings are given and you have to modify 1st string such that all the common characters of the 2nd strings have to be removed and the uncommon characters of the 2nd string have to be concatenated with uncommon characters of the 1st string.

Example
Given s1 = aacdb, s2 = gafd
return cbgf

Given s1 = abcs, s2 = cxzca;
return bsxz

Tags 
Hash Table String Microsoft
Related Problems 
Easy Split String
*/

class Solution {
public:
    /*
     * @param : the 1st string
     * @param : the 2nd string
     * @return: uncommon characters of given strings
     */
    string concatenetedString(string &s1, string &s2) {
        // write your code here
        vector<char> mp(26, 0);
        for (auto c : s1)
            mp[c - 'a'] = 0x1;
        for (auto c : s2) {
            if (mp[c - 'a'] & 0x3)
                mp[c - 'a'] = 0x3;
            else
                mp[c - 'a'] = 0x4;
        }
        string res = "";
        for (auto c : s1) {
            if (mp[c - 'a'] != 0x3)
                res.push_back(c);
        }
        for (auto c : s2) {
            if (mp[c - 'a'] != 0x3)
                res.push_back(c);
        }
        return res;
    }
};
