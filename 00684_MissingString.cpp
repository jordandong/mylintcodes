/*
Given two strings, you have to find the missing string.

Have you met this question in a real interview? Yes
Example
Given a string str1 = This is an example
Given another string str2 = is example

Return ["This", "an"]

Tags 
Hash Table
*/

class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string str1, string str2) {
        // Write your code here
        unordered_set<string> st;
        string w = "";
        for (int j = 0; j < str1.length(); j++) {
            if ('a' <= str1[j] && str1[j] <= 'z' || 'A' <= str1[j] && str1[j] <= 'Z') {
               w.push_back(str1[j]); 
            } else {
                if (w != "") {
                    st.insert(w);
                    w = "";
                }
            }
        }
        
        if (w != "") {
            st.insert(w);
            w = "";
        }
        
        for (int j = 0; j < str2.length(); j++) {
            if ('a' <= str2[j] && str2[j] <= 'z' || 'A' <= str2[j] && str2[j] <= 'Z') {
               w.push_back(str2[j]); 
            } else {
                if (w != "" && st.find(w) != st.end()) {
                    st.erase(w);
                    w = "";
                }
            }
        }
        
        if (w != "" && st.find(w) != st.end()) {
            st.erase(w);
            w = "";
        }
                
        return vector<string>(st.begin(), st.end());
    }
};
