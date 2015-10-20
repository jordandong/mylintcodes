/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:
1. void addNum(int num) - Add a integer number from the data stream to the data structure.
2. double findMedian() - Return the median of all elements so far.

For example:
add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.

Hide Tags Heap Design
*/

class MedianFinder {
public:
    priority_queue<int> large, small;//[2];
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (large.size() > small.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return large.size() < small.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
