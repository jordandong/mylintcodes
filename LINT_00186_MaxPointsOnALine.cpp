/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Have you met this question in a real interview? Yes

Example
Given 4 points: (1,2), (3,6), (0,0), (1,3).
The maximum number is 3.

Tags Expand 
Hash Table Mathematics
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
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int maxNum = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<float, int> statistic;
            int duplicate = 0;
            int maxInLine = 0;
            for (int j = 0; j < points.size(); j++){
                //count duplicate
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                float key = (points[j].x - points[i].x) == 0 ?
                            INT_MAX : // key for vertical line
                            (float) (points[j].y - points[i].y) / (points[j].x - points[i].x);
                statistic[key]++;
                maxInLine = max(maxInLine, statistic[key]);
            }
            maxNum = max(maxNum, maxInLine + duplicate);
        } 
        return maxNum;
    }
};
