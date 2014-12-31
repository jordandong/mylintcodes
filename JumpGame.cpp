/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int sz = A.size();
        if(sz == 0)
            return true;
        
        int range = A[0];
        for(int i=0; i<=range; i++){
            if(A[i] + i > range)
                range = A[i] + i;
            if (range >= sz-1)
                return true;
        }
        return false;
    }
};
