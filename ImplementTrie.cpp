/*
Implement a trie with insert, search, and startsWith methods.

Have you met this question in a real interview? Yes

Example

Note
You may assume that all inputs are consist of lowercase letters a-z.

Tags Expand 
Trie
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur_node = root;
        for (auto & c : word) {
            int idx = c - 'a';
            if (cur_node->next_node[idx] == NULL)
                cur_node->next_node[idx] = new TrieNode();
            cur_node = cur_node->next_node[idx];
        }
        cur_node->is_last_node = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur_node = root;
        for (auto & c : word) {
            int idx = c - 'a';
            if (cur_node->next_node[idx] == NULL)
                return false;
            cur_node = cur_node->next_node[idx];
        }
        return cur_node->is_last_node;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur_node = root;
        for (auto & c : prefix) {
            int idx = c - 'a';
            if (cur_node->next_node[idx] == NULL)
                return false;
            cur_node = cur_node->next_node[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};
