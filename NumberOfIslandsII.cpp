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
        int number = 0;
        vector<int> numbers;
        unordered_map<int, int> sets;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},{-1, 0}, {1, 0}};
        
        for (const auto& oper : operators) {
            const auto& node = make_pair(oper.x, oper.y);
            //create a single set
            sets[node_id(node, m)] = node_id(node, m);
            //For each direction, count distinct islands.
            unordered_set<int> neighbors;
            for (const auto& d : directions) {
                const auto& neighbor = make_pair(oper.x + d.first, oper.y + d.second);
                if (neighbor.first >= 0 && neighbor.first < n &&
                    neighbor.second >= 0 && neighbor.second < m &&
                    sets.find(node_id(neighbor, m)) != sets.end()) {
                    //already in the sets, update neighbor, each island has different key
                    neighbors.insert(find_set(node_id(neighbor, m), sets));
                }
            }
            // For each direction, find and union.
            for (const auto& d : directions) {
                const auto& neighbor = make_pair(oper.x + d.first, oper.y + d.second);
                if (neighbor.first >= 0 && neighbor.first < n &&
                    neighbor.second >= 0 && neighbor.second < m &&
                    sets.find(node_id(neighbor, m)) != sets.end()) {
                    //already in the sets, union sperate sets
                    union_set(node_id(node, m), node_id(neighbor, m), sets);
                }
            }
            number += (1 - neighbors.size());
            numbers.push_back(number);
        }
        return numbers;
    }

    int node_id(const pair<int, int>& node, const int m) {
        //make the node unique
        return node.first * m + node.second;
    }

    int find_set(int x, unordered_map<int, int> &sets) {
       if (sets[x] != x) //different nodes in the same set has the same key
           sets[x] = find_set(sets[x], sets);
       return sets[x];
    }

    void union_set(const int x, const int y, unordered_map<int, int> &sets) {
        int x_key = find_set(x, sets);
        int y_key = find_set(y, sets);
        //different nodes in the same set has the same key
        sets[min(x_key, y_key)] = max(x_key, y_key);
    }
};

//update island idx for each union, TLE
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
            
            if (p.x - 1 >= 0 && mp[p.x - 1][p.y]) {
                if (mp[p.x][p.y] == 0) {
                    mp[p.x][p.y] = mp[p.x - 1][p.y];
                    count--;
                } else if (mp[p.x][p.y] != mp[p.x - 1][p.y]) {
                    numIslands2Helper(p.x - 1, p.y, mp[p.x][p.y], mp);
                    count--;
                }
            }
            
            if (p.x + 1 < n && mp[p.x + 1][p.y]) {
                if (mp[p.x][p.y] == 0) {
                    mp[p.x][p.y] = mp[p.x + 1][p.y];
                    count--;
                } else if (mp[p.x][p.y] != mp[p.x + 1][p.y]) {
                    numIslands2Helper(p.x + 1, p.y, mp[p.x][p.y], mp);
                    count--;
                }
            }
            
            if (p.y - 1 >= 0 && mp[p.x][p.y - 1]) {
                if (mp[p.x][p.y] == 0) {
                    mp[p.x][p.y] = mp[p.x][p.y - 1];
                    count--;
                } else if (mp[p.x][p.y] != mp[p.x][p.y - 1]) {
                    numIslands2Helper(p.x, p.y - 1, mp[p.x][p.y], mp);
                    count--;
                }
            }
            
            if (p.y + 1 < m && mp[p.x][p.y + 1]) {
                if (mp[p.x][p.y] == 0) {
                    mp[p.x][p.y] = mp[p.x][p.y + 1];
                    count--;
                } else if (mp[p.x][p.y] != mp[p.x][p.y + 1]) {
                    numIslands2Helper(p.x, p.y + 1, mp[p.x][p.y], mp);
                    count--;
                }
            }
            
            if(mp[p.x][p.y] == 0)
                mp[p.x][p.y] = idx;

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
