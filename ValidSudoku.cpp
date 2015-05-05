/*
Determine whether a Sudoku is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character ..

Example
The following partially filed sudoku is valid.
53..7....    
6..195...   
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

Note
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Clarification
What is Sudoku?
http://sudoku.com.au/TheRules.aspx
https://zh.wikipedia.org/wiki/%E6%95%B8%E7%8D%A8
https://en.wikipedia.org/wiki/Sudoku
http://baike.baidu.com/subview/961/10842669.htm

Tags Expand 
Matrix
*/

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        int M = board.size();
        if(M != 9)
            return false;
        int N = board[0].size();
        if(N != 9)
            return false;
        
        for(int i = 0; i < M ; i++){
            int col = 0, row = 0, blk = 0;
            int v = 0;
            for(int j = 0; j < N; j++){
                if(board[i][j] != '.'){
                    v = board[i][j] - '0';
                    if(v <= 0 || v > 9)
                        return false;
                    if(col & 1<<v)
                        return false;
                    else
                        col |= 1<<v;
                }
                if(board[j][i] != '.'){
                    v = board[j][i] - '0';
                    if(v <= 0 || v > 9)
                        return false;
                    if(row & 1<<v)
                        return false;
                    else
                        row |= 1<<v;
                }
                if(board[i/3*3 + j/3][i%3*3 + j%3] != '.'){
                    v = board[i/3*3 + j/3][i%3*3 + j%3] - '0';
                    if(v <= 0 || v > 9)
                        return false;
                    if(blk & 1<<v)
                        return false;
                    else
                        blk |= 1<<v;
                }
            }
        }
        return true;
    }
};
