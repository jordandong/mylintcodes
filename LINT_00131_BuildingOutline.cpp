/*
Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. Buildings may overlap if you see them from far away，find the outline of them.
An outline can be represented by a triple, (start, end, height), where start is the start position on x-axis of the outline, end is the end position on x-axis and height is the height of the outline.

Building Outline
 ***
****
****
******
123456

Example
Given 3 buildings：
[
  [1, 3, 3],
  [2, 4, 4],
  [5, 6, 1]
]

The outlines are：
[
  [1, 2, 3],
  [2, 4, 4],
  [5, 6, 1]
]

Note
Please merge the adjacent outlines if they have the same height and make sure different outlines cant overlap on x-axis.

Tags Expand 
LintCode Copyright Heap
*/

class Solution {
public:
    enum{
        start = 0,
        end,
        height
    };
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        int N = buildings.size();
        if(N == 0)
            return vector<vector<int> >();
        return buildingOutlineHelper(buildings, 0, N - 1);
    }
    
    // Divide
    vector<vector<int> > buildingOutlineHelper(vector<vector<int>>& buildings, int l, int r) {
        if (l == r)
            return vector<vector<int> > (1, buildings[l]);

        int mid = l + (r - l) / 2;
        auto l_rtn = buildingOutlineHelper(buildings, l, mid);
        auto r_rtn = buildingOutlineHelper(buildings, mid + 1, r);
        return buildingOutlineMerge(l_rtn, r_rtn);
    }
    
    // Merge
    vector<vector<int> > buildingOutlineMerge(vector<vector<int>>& l_rtn, vector<vector<int>>& r_rtn) {
        int i = 0, j = 0;
        vector<vector<int>> rtn;
        
        while (i < l_rtn.size() && j < r_rtn.size()) {
            if (l_rtn[i][end] < r_rtn[j][start]) { //l is separated 
                rtn.push_back(l_rtn[i++]);
            } else if (r_rtn[j][end] < l_rtn[i][start]) { //r is separated
                rtn.push_back(r_rtn[j++]);
            } else if (l_rtn[i][start] <= r_rtn[j][start]) {//small start is always as the first argu
                MergeInterval(rtn, l_rtn[i], i, r_rtn[j], j);
            } else {
                MergeInterval(rtn, r_rtn[j], j, l_rtn[i], i);
            }
        }
        
        // remaining l/r_rtn
        if(i < l_rtn.size())
            rtn.insert(rtn.end(), l_rtn.begin() + i, l_rtn.end());
        if(j < r_rtn.size())
            rtn.insert(rtn.end(), r_rtn.begin() + j, r_rtn.end());
        return rtn;
    }
    
    void MergeInterval(vector<vector<int> >& rtn, vector<int>& x, int& x_i, vector<int>& y, int& y_i) {
        if (x[end] <= y[end]) { // x overlays y
            if (x[height] > y[height]) {
                if (x[end] != y[end]) { //x covers y, add x, update y start
                    rtn.push_back(x);
                    x_i++;
                    y[start] = x[end];
                } else { // x covers y fully, remove y
                    y_i++; 
                }
            } else if (x[height] == y[height]) { //x connects y with same height, update y start with smaller one, remove x
                y[start] = x[start];
                x_i++;
            } else { // y covers x
                if (x[start] != y[start]) { //add part of x
                    rtn.push_back(vector<int>{x[start], y[start], x[height]});
                }
                x_i++; //remove x
            }
        } else { //x contains whole y
            if (x[height] >= y[height]) { //x fully covers y, remove y, update x start with the remaning
                y_i++;
            } else { //add first part of x and whole y
                if (x[start] != y[start]) {
                    rtn.push_back(vector<int>{x[start], y[start], x[height]});
                }
                rtn.push_back(y);
                y_i++;
                x[start] = y[end];
            }
        }
    }
};
