/*
Give a dictionary of words and a sentence with all whitespace removed,
return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Example
Given a String CatMat
Given a dictionary ["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
return 3

We can form 3 sentences, as follows:
CatMat = Cat Mat
CatMat = Ca tM at
CatMat = C at Mat

Tags 
Backtracking Depth First Search
*/

class Solution {
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string& s, unordered_set<string>& dict) {
        // Write your code here
        int res = 0;
        wordBreak3Helper(s, 0, res, dict);
        return res;
        
    }
    
    void wordBreak3Helper(string& s, int idx, int &res, unordered_set<string>& dict) {
        int N = s.length();
        if (idx >= N) {
            res++;
            return;
        }
        
        for (int i = idx; i < N; i++) {
            string w =  s.substr(idx, i - idx + 1);
            if (dict.find(w) == dict.end())
                continue;
            wordBreak3Helper(s, i + 1, res, dict);
        }
     }
};
