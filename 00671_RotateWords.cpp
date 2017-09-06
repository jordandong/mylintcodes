/*
The words are same rotate words if rotate the word to the right by loop, and get another.
Count how many different rotate word sets in dictionary.

E.g. picture and turepic are same rotate words.

Notice
All words are lowercase.

Example
Given dict = ["picture", "turepic", "icturep", "word", "ordw", "lint"]
return 3.
"picture", "turepic", "icturep" are same ratote words.
"word", "ordw" are same too.
"lint" is the third word that different from the previous two words.

Tags 
String
*/

class Solution {
public:
    /*
     * @param words: A list of words
     * @return: Return how many different rotate words
     */
    int countRotateWords(vector<string> words) {
        // Write your code here
        set<string> st;
        int res = 0;
        for (auto w : words) {
            if (st.find(w) == st.end()) {
                res++;
                for (int i = 0; i < w.length(); i++) {
                    string t = w.substr(i) + w.substr(0, i);
                    st.insert(t);
                }
            }
        }
        return res;
    }
};
