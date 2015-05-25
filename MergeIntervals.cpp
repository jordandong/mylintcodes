/*
Given a collection of intervals, merge all overlapping intervals.
Have you met this question in a real interview? Yes

Example
Given intervals => merged intervals:
[                     [
  [1, 3],               [1, 6],
  [2, 6],      =>       [8, 10],
  [8, 10],              [15, 18]
  [15, 18]            ]
]

Challenge
O(n log n) time and O(1) extra space.

Tags Expand 
Sort Array
*/

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class cmp_intervals {
public:
    bool operator() (Interval i, Interval j) {
        return (i.start < j.start);
    }
};

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if(intervals.size() < 2)
            return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp_intervals());
        Interval cur = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].start <= cur.end){
                cur.start = min(intervals[i].start, cur.start);
                cur.end = max(intervals[i].end, cur.end);
                continue;
            }
            res.push_back(cur);
            cur = intervals[i];
        }
        res.push_back(cur);
        return res;
    }
};
