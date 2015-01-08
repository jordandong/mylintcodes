/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int sz = A.size();
        int lo = 0;
        int hi = sz - 1;
        vector<int> res(2, -1);
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(A[mid] >= target){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(lo == sz || A[lo]!=target)
            return res;
        
        res[0] = lo;
        lo = 0;
        hi = sz - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(A[mid] <= target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        res[1] = hi;
        return res;
    }
};
