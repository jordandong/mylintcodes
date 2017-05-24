/*
Given n * m non-negative integers representing an elevation map 2d where the area of each cell is 1 * 1, compute how much water it is able to trap after raining.

Example
For example, Given 5*4 matrix
[12,13,0,12]
[13,4,13,12]
[13,8,10,12]
[12,13,12,12]
[13,13,13,13]
, return 14.

Tags Expand 
Heap Matrix
*/

/*
For every point on the border set the water level to the point height
For every point not on the border set the water level to infinity
Put every point on the border into the set of active points
While the set of active points is not empty:
    Select the active point P with minimum level
    Remove P from the set of active points
    For every point Q adjacent to P:
        Level(Q) = max(Height(Q), min(Level(Q), Level(P)))
        If Level(Q) was changed:
            Add Q to the set of active points
Similar to D-J Algo
*/

struct lv_pts{
    int x;
    int y;
    int lv;
};

class cmp{
public:    
    bool operator() (const lv_pts &lp1, const lv_pts &lp2){
        return lp1.lv > lp2.lv;
    }
};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        int m = heights.size();
        if(m == 0)
            return 0;
        int n = heights[0].size();
        if(n == 0)
            return 0;
        priority_queue<lv_pts, vector<lv_pts>, cmp> q;
        vector<vector<int> > lv = heights;
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    lv_pts p;
                    p.x = i;
                    p.y = j;
                    p.lv = heights[i][j];
                    q.push(p);
                }else{
                    lv[i][j] = INT_MAX;
                }
            }
        }
        
        while(q.size()){
            lv_pts c = q.top();
            q.pop();
            res += (c.lv - heights[c.x][c.y]);
            if(c.x - 1 >= 0)
                check_adj(c.x - 1, c.y, c.lv, q, lv, heights);
            if(c.x + 1 < m)
                check_adj(c.x + 1, c.y, c.lv, q, lv, heights);
            if(c.y - 1 >= 0)
                check_adj(c.x, c.y - 1, c.lv, q, lv, heights);
            if(c.y + 1 < n)
                check_adj(c.x, c.y + 1, c.lv, q, lv, heights);
        }
        return res;
    }
    
    void check_adj(int x, int y, int lv, priority_queue<lv_pts, vector<lv_pts>, cmp> &q, vector<vector<int> > &v, vector<vector<int> > &h){
        int t = max(min(lv, v[x][y]), h[x][y]);
        if(t != v[x][y]){
            v[x][y] = t;
            lv_pts pts;
            pts.x = x;
            pts.y = y;
            pts.lv = t;
            q.push(pts);
        }
    }
};
