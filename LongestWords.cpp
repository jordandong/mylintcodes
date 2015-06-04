/*
Given a dictionary, find all of the longest words in the dictionary.

Have you met this question in a real interview? Yes

Example
Given
{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}
the longest words are(is) ["internationalization"].

Given
{
  "like",
  "love",
  "hate",
  "yes"
}
the longest words are ["like", "love", "hate"].

Challenge
It's easy to solve it in two passes, can you do it in one pass?

Tags Expand 
Enumeration String LintCode Copyright
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        for (auto w : dictionary) {
            if (res.size() && w.length() > res.back().length())
                res.clear();
            if (res.empty() || w.length() == res.back().length())
                res.push_back(w);
        }
        return res;
    }
};
