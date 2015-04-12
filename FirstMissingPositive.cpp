/*
Given an unsorted integer array, find the first missing positive integer.

Example
Given [1,2,0] return 3, and [3,4,-1,1] return 2.

Challenge
Your algorithm should run in O(n) time and uses constant space.

Tags Expand 
Array
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int i = 0;
        while(i < A.size()){
            if(A[i] - 1 >= 0 && A[i] - 1 < A.size() && A[i] != A[A[i] - 1])
                swap(A[A[i] - 1], A[i]);
            else
                i++;
        }
        
        for(i = 0; i < A.size(); i++)
            if(A[i] != i + 1)
                break;
        return i + 1;
    }
};
