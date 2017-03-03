/*
Given a boolean 2D matrix, find the number of islands.

Have you met this question in a real interview? Yes

Example
Given graph:
[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.

Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int res = 0;
        int M = grid.size();
        if(M == 0)
            return res;
        int N = grid[0].size();
        if(N == 0)
            return res;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j]){
                    res++;
                    numIslandsHelper(i, j, grid);
                }
            }
        }
        return res;
    }
  
    void numIslandsHelper(int i, int j, vector<vector<bool> > &grid) {
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        grid[i][j] = false;
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i + 1 < grid.size() && grid[i + 1][j]){
                grid[i + 1][j] = false;
                q.push(make_pair(i + 1, j));
            }
            if(i - 1 >= 0 && grid[i - 1][j]){
                grid[i - 1][j] = false;
                q.push(make_pair(i - 1, j));
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1]){
                grid[i][j + 1] = false;
                q.push(make_pair(i, j + 1));
            }
            if(j - 1 >= 0 && grid[i][j - 1]){
                grid[i][j - 1] = false;
                q.push(make_pair(i, j - 1));
            }
        }
    }
};
