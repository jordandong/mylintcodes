/*
Symbol string generator consists of two parts, a set of the start symbol and a set of rules of generation.
For example:
Start symbol: ['S'], Rules of generation: ["S → abc", "S → aA", "A → b", "A → c"]
Then, symbolic string abc can be generated because S → abc. 
Symbolic string ab can be generated because S → aA → ab.
Symbolic string abc can be generated because S → aA → ac.
Now, give you a symbolic string generator and a symbolic string, and you need to return True if the symbolic string can be generated, False otherwise

 Notice
You can assume the left side of the generation rule is an uppercase letter, startSymbol is an uppercase letter, symbolString is a lowercase string
|generator| <= 20, |symbolString| <= 20
There is no left recursion in generate rule sets. For example, there is no such rule set as ["S → Sb", "S → A", "A → Sb"]
Have you met this question in a real interview? Yes
Example
Given generator = ["S → abc", "S → aA", "A → b", "A → c"], startSymbol = S, symbolString = “ac”, return True.

explanation:
S -> aA -> ac
Given generator = ["S → abcd", "S → A", "A → abc"], startSymbol = S, symbolString = “abc”, return True

explanation:
S → A → abc
Given generator = ["S → abc", "S → aA", "A → b", "A → c"], startSymbol = S, symbolString = “a”, return False

explanation:
S after several steps cannot get a
Given generator = ["S → abcd", "S → A", "A → abc"], startSymbol = S, symbolString = “ab”, return True

explanation:
S after several steps cannot get ab
*/

class Solution {
public:
    /**
     * @param generator: Generating set of rules.
     * @param startSymbol: Start symbol.
     * @param symbolString: Symbol string.
     * @return: Return true if the symbol string can be generated, otherwise return false.
     */
    bool canBeGenerated(vector<string> &generator, char startSymbol, string &symbolString) {
        // Write your code here.
        unordered_map<char, vector<string>> mp;
        for (auto g : generator) {
            char left;
            string right = "";
            bool found = false;
            for (int i = 0; i < g.length(); i++) {
                if (g[i] == '-' || g[i] == '>')
                    found = true;
                else if (isalpha(g[i])) {
                    if (found)
                        right.push_back(g[i]);
                    else
                        left = g[i];
                }
            }
            mp[left].push_back(right);
        }
        
        for (int i = 0; i < mp[startSymbol].size(); i++) {
            if (canBeGeneratedHelper(mp, mp[startSymbol][i], 0, symbolString))
                return true;
        }
        return false;
    }
    
    
    bool canBeGeneratedHelper(unordered_map<char, vector<string>> &mp, string start, int i, string symbolString) {
        if (start.length() > symbolString.length())
            return false;
        if (start == symbolString)
            return true;
        
        while (i < start.length()) {
            if (mp.find(start[i]) != mp.end()) {
                for (int j = 0; j < mp[start[i]].size(); j++) {
                    string tmp = start.substr(0, i);
                    tmp += mp[start[i]][j];
                    tmp += start.substr(i + 1);
                    if (canBeGeneratedHelper(mp, tmp, i, symbolString))
                        return true;
                }
            }
            i++;
        }
        return false;
    }
};
