/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int lo = 0;
        int hi = A.size()-1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(A[mid] == target || A[lo] == target || A[hi] == target)
                return true;
            if(A[mid] > A[lo]){
                if(target > A[lo] && target < A[mid]){
                    hi = mid -1;
                }else{
                    lo = mid + 1;
                }
            }else if(A[mid] < A[hi]){
                if(target < A[hi] && target > A[mid]){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }else{
                lo++;
            }
        }
        
        return false;
    }
};
