/*
Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?

Example
For interval list [[1,10],[2,3],[5,8],[4,7]], return 3

Note
If landing and flying happens at the same time, we consider landing should happen at first.

Tags Expand 
LintCode Copyright Array Interval
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class pq_comp{
public:
    bool operator() (const int &a, const int &b) {
        return a > b;
    }
};

bool sort_comp (Interval i, Interval j) {
    return i.start < j. start;
}

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int N = airplanes.size();
        if(N == 0)
            return 0;
        int res = 0;
        priority_queue<int, vector<int>, pq_comp> q;
        sort(airplanes.begin(), airplanes.end(), sort_comp);
        for (int i = 0; i < N; i++) {
            while (q.size() && q.top() <= airplanes[i].start)//landing happens before taking off
                q.pop();
            q.push(airplanes[i].end);//landing times in q, max in the sky at the same time
            res = res > q.size() ? res : q.size();
        }
        return res;
    }
};
