/*
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island.
If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands that size bigger than K.

Example
Given graph:
[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
Given the K = 2

return 2
*/

class Solution {
public:
    /*
     * @param : a 2d boolean array
     * @param : an integer
     * @return: the number of Islands
     */
    int numsofIsland(vector<vector<bool>> grid, int k) {
        // Write your code here
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int cnt = 0;
                    numsofIslandHelper(grid, i, j, cnt);
                    if (cnt >= k)
                        res++;
                }
            }
        }
        return res;
    }

private:
    void numsofIslandHelper(vector<vector<bool>> &grid, int x, int y, int &cnt) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || m <= x || y < 0 || n <= y || grid[x][y] == 0)
            return;
        grid[x][y] = false;
        cnt++;
        numsofIslandHelper(grid, x - 1, y, cnt);
        numsofIslandHelper(grid, x + 1, y, cnt);
        numsofIslandHelper(grid, x, y - 1, cnt);
        numsofIslandHelper(grid, x, y + 1, cnt);
    }
};
