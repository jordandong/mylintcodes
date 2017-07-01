/*
Given some points and a point origin in two dimensional space, find k points out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance, sorted by x-axis, otherwise sorted by y-axis.

Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]

Tags 
LinkedIn Heap Amazon
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
     * @param points a list of points
     * @param origin a point
     * @param k an integer
     * @return the k closest points
     */
     
    struct cmp {
        bool operator ()(const Point &a, const Point &b) const {
            int dis_a = a.x * a.x + a.y * a.y;
            int dis_b = b.x * b.x + b.y * b.y;
            if (dis_a == dis_b) {
                if (a.x == b.x)
                    return a.y < b.y;
                return a.x < b.x;
            }
            return dis_a < dis_b;
        }
    };
    
    vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
        // Write your code here
        vector<Point> res;
        priority_queue<Point, vector<Point>, cmp> q;
    
        for (int i = 0; i < points.size(); i++) {
            Point np;
            np.x = points[i].x - origin.x;
            np.y = points[i].y - origin.y;
            if (i < k) {
                q.push(np);
            } else {
                Point t = q.top();
                if ((np.x*np.x + np.y*np.y) <= (t.x*t.x + t.y*t.y)) {
                    q.pop();
                    q.push(np);
                }
            }
        }
        
        while (!q.empty()) {
            Point op;
            op.x = q.top().x + origin.x;
            op.y = q.top().y + origin.y;
            res.push_back(op);
            q.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
