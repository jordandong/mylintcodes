/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O''s into 'X''s in that surrounded region.

Have you met this question in a real interview? Yes

Example
X X X X
X O O X
X X O X
X O X X

After capture all regions surrounded by 'X', the board should be:
X X X X
X X X X
X X X X
X O X X

Tags Expand 
Breadth First Search Union Find
*/

class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int M = board.size();
        if(M == 0)
            return;
        int N = board[0].size();
        if(N == 0)
            return;
        
        dummy_char = 'F';
        for(int i = 0; i < M; i++){
            fill(i, 0, board);
            fill(i, N - 1, board);
        }
        for(int j = 0; j < N; j++){
            fill(0, j, board);
            fill(M - 1, j, board);
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == dummy_char)
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void fill(int i, int j, vector<vector<char>> &board){
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'O')
                continue;
            
            board[x][y] = dummy_char;
            q.push(make_pair(x + 1, y));
            q.push(make_pair(x - 1, y));
            q.push(make_pair(x, y + 1));
            q.push(make_pair(x, y - 1));
        }
    }
private:
    char dummy_char;
};
