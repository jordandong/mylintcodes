/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int lo = 0;
        int hi = A.size()-1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(A[mid] == target){
                return mid;
            }
            if(target > A[mid]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};
