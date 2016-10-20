/*
Given an array of strings, return all groups of strings that are anagrams.

Note
All inputs will be in lower-case

Example
Given a string list: ["lint","intl","inlt","code"]

return ["lint","inlt","intl"]
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string , string> mp;
        vector<string> res;
        for(string s : strs){
            string t = s;
            sort(s.begin(), s.end());
            if(mp.find(s) != mp.end()){
                if(mp[s].compare("*"))
                    res.push_back(mp[s]);
                res.push_back(t);
                mp[s] = "*";
            }else{
                mp[s] = t;
            }
        }
        return res;
    }
};
