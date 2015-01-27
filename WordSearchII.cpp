/*
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix.
A word can start from any position in the matrix and go left/right/up/down to the adjacent position. 

Example:
Given matrix:
doaf
agai
dcan
and dictionary:
{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}

dog:
doaf
agai
dcan

dad:
doaf
agai
dcan

can:
doaf
agai
dcan

again:
doaf
agai
dcan

Challenge:
Using trie to implement your algorithm.
*/

class TrieNode {
public:
    TrieNode *next[26];
    bool word_end;
    
    TrieNode(){
        memset(next, 0, 26*sizeof(TrieNode*));
        word_end = false;
    }
    
    ~TrieNode() {
        for(int i = 0; i < 26; i++){
            if(next[i])
                delete next[i];
        }
    }
    
    void Add(string &s, int idx) {
        if(idx == s.length()){
            word_end = true; // record the end of each word
            return;
        }
        if(next[s[idx] - 'a'] == NULL)
            next[s[idx] - 'a'] = new TrieNode();
        next[s[idx]-'a']->Add(s, idx + 1);
    }
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        vector<string> res;
        TrieNode node; 
        for(int i = 0; i < words.size(); i++) 
            node.Add(words[i], 0);
        
        string sol = "";
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j< board[0].size(); j++)
                wordSearchIIHelper(board, &node, i, j, sol, res); 
        return res;
    }
    
    void wordSearchIIHelper(vector<vector<char> > &board, TrieNode *node, int i, int j, string &sol,vector<string> &res){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
             
        if (board[i][j] == '*' || !node->next[board[i][j]-'a'])
            return;
        
        char tmp = board[i][j];
        TrieNode *nextNode = node->next[board[i][j]-'a'];
        sol.push_back(board[i][j]);
        if(nextNode->word_end){
            res.push_back(sol);
            nextNode->word_end = false; // avoid the dup
        }
            
        board[i][j] = '*';
        wordSearchIIHelper(board, nextNode, i + 1, j, sol, res);  
        wordSearchIIHelper(board, nextNode, i, j + 1, sol, res);  
        wordSearchIIHelper(board, nextNode, i - 1, j, sol, res);  
        wordSearchIIHelper(board, nextNode, i, j - 1, sol, res);
        board[i][j] = tmp;
        sol.erase(sol.length()-1);
    } 
};
