/*
Given k strings, find the longest common prefix (LCP).

Example
For strings "ABCD" "ABEF" and "ACEF", the LCP is "A"
For strings "ABCDEFG", "ABCEFG", "ABCEFA", the LCP is "ABC"

Tags Expand 
Enumeration Basic Implementation LintCode Copyright
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        int sz = strs.size();
        int l = 0;
        char c;
        if(sz == 0)
            return "";

        for(int l = 0; l < (int)strs[0].size(); l++){
            char c = strs[0][l];
            for(int i = 1; i < sz; i++){
                if(l == (int)strs[i].size() || strs[i][l] != c){
                    return strs[0].substr(0, l);
                }
            }
        }
        return strs[0];
    }
};
