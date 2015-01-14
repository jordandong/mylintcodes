/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
Given board =
[
  "ABCE",
  "SFCS",
  "ADEE"
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int l = word.length();
        if(l == 0)
            return true;
        int m = board.size();
        if(m == 0)
            return false;
        int n = board[0].size();
        if(n == 0)
            return false;
            
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(exsitHelper(board, word, 0, i, j, m, n))
                    return true;
            }
        }
        return false;
    }
    
    bool exsitHelper(vector<vector<char> > &board, string &word, int start, int row, int col, int m, int n){
        if(start == word.length())
            return true;
        if(row < 0 || row >= m || col < 0 || col >= n)
            return false;
        if(word[start]!=board[row][col])
            return false;
        
        char tmp = word[start];
        board[row][col] = '*';
        if(exsitHelper(board, word, start+1, row+1, col, m, n) || 
           exsitHelper(board, word, start+1, row, col+1, m, n) ||
           exsitHelper(board, word, start+1, row-1, col, m, n) ||
           exsitHelper(board, word, start+1, row, col-1, m, n)){
            board[row][col] = tmp;
            return true;
        }
        board[row][col] = tmp;
        return false;
    }
};
