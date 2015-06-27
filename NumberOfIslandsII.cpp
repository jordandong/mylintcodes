/*
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.

Have you met this question in a real interview? Yes

Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].
return [1,1,2,2].

Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Tags Expand 
Union Find
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
 //TLE
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        int N = operators.size();
        if(N == 0)
            return {};
        vector<vector<int>> mp(n, vector<int>(m, 0));
        vector<int> res(N, 0);
        int idx = 1;
        
        for (int i = 0; i < N; i++, idx++) {
            int count = 1;
            Point &p = operators[i];
            if (mp[p.x][p.y]) {
                res[i] = res[i - 1];
                continue;
            }
            
            mp[p.x][p.y] = idx;
            if (p.x - 1 >= 0 && mp[p.x - 1][p.y] && mp[p.x - 1][p.y] != idx) {
                count--;
                numIslands2Helper(p.x - 1, p.y, idx, mp);
            }
            if (p.x + 1 < n && mp[p.x + 1][p.y] && mp[p.x + 1][p.y] != idx) {
                count--;
                numIslands2Helper(p.x + 1, p.y, idx, mp);
            }
            if (p.y - 1 >= 0 && mp[p.x][p.y - 1] && mp[p.x][p.y - 1] != idx) {
                count--;
                numIslands2Helper(p.x, p.y - 1, idx, mp);
            }
            if (p.y + 1 < m && mp[p.x][p.y + 1] && mp[p.x][p.y + 1] != idx) {
                count--;
                numIslands2Helper(p.x, p.y + 1, idx, mp);
            }
            if(i == 0)
                res[i] = count;
            else
                res[i] = res[i - 1] + count;
        }
        return res;
    }
    
    void numIslands2Helper(int i, int j, int idx, vector<vector<int>> &grid) {
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        grid[i][j] = idx;
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i + 1 < grid.size() && grid[i + 1][j] && grid[i + 1][j] != idx){
                grid[i + 1][j] = idx;
                q.push(make_pair(i + 1, j));
            }
            if(i - 1 >= 0  && grid[i - 1][j] && grid[i - 1][j] != idx){
                grid[i - 1][j] = idx;
                q.push(make_pair(i - 1, j));
            }
            if(j + 1 < grid[0].size()  && grid[i][j + 1] && grid[i][j + 1] != idx){
                grid[i][j + 1] = idx;
                q.push(make_pair(i, j + 1));
            }
            if(j - 1 >= 0 && grid[i][j - 1] && grid[i][j - 1] != idx){
                grid[i][j - 1] = idx;
                q.push(make_pair(i, j - 1));
            }
        }
    }
};
