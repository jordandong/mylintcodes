/*
Given an array and a value, remove all occurrences of that value in place and return the new length.
The order of elements can be changed, and the elements after the new length don't matter.

Example:
Given an array [0,4,4,0,0,2,4,4], value=4
return 4 and front four elements of the array is [0,0,0,2]
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int lo = 0;
        int hi = A.size() - 1;
        while(lo <= hi){
            if(A[lo] == elem)
                swap(A[lo], A[hi--]);
            else
                lo++;
        }
        return hi + 1;
    }
};
