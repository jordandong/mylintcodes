/*
Find any position of a target number in a sorted array.
Return -1 if target does not exist.

Example
Given [1, 2, 2, 4, 5, 5].
For target = 2, return 1 or 2.
For target = 5, return 4 or 5.
For target = 6, return -1.

Challenge 
O(logn) time

Tags 
Binary Search
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        int lo = 0, hi = A.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (target == A[mid])
                return mid;
            if (target > A[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};
