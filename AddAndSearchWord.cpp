/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Have you met this question in a real interview? Yes

Example
addWord("bad")
addWord("dad")
addWord("mad")

search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note
You may assume that all words are consist of lowercase letters a-z.

Tags Expand 
Backtracking
*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        memset(next_node, 0 , sizeof(next_node));
        is_last_node = false;
    }
public:
    TrieNode* next_node[26];
    bool is_last_node;
};

class WordDictionary {
public:
    WordDictionary () {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        TrieNode *cur_node = root;
        for (auto & c : word) {
            int idx = c - 'a';
            if (cur_node->next_node[idx] == NULL)
                cur_node->next_node[idx] = new TrieNode();
            cur_node = cur_node->next_node[idx];
        }
        cur_node->is_last_node = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return searchHelper(word, root);
    }
    
    bool searchHelper(string word, TrieNode* root) {
        // Write your code here
        int L = word.length();
        if (L == 0)
            return root->is_last_node;
        if (word[0] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->next_node[i]) {
                    if (searchHelper(word.substr(1), root->next_node[i]))
                        return true;
                }
            }
            return false;
        } else {
            if (root->next_node[word[0] - 'a'] == NULL)
                return false;
            return searchHelper(word.substr(1), root->next_node[word[0] - 'a']);
        }
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
