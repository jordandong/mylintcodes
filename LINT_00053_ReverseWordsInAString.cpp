/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Example
Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string res;
        stack<char> stk;
        int sz = s.length();
        for(int i = sz -1; i>=0; i--){
            char c = s[i];
            if(c == ' '){
                if(!stk.empty()){
                    while(!stk.empty()){
                        res.push_back(stk.top());
                        stk.pop();
                    }
                    res.push_back(c);
                }
            }else{
                stk.push(c);
            }
        }
        while(!stk.empty()){
            if(stk.top()!= ' ')
                res.push_back(stk.top());
            stk.pop();
        }
        if(res.back() == ' ')
            res.pop_back();
        return res;
    }
};
