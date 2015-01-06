/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

    * Integers in each row are sorted from left to right.

    * The first integer of each row is greater than the last integer of the previous row.

Example:
Consider the following matrix:
[

    [1, 3, 5, 7],

    [10, 11, 16, 20],

    [23, 30, 34, 50]

]
Given target = 3, return true.

Challenge:
O(log(n) + log(m)) time
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        
        int lo = 0;
        int hi = m -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[mid][n-1] == target)
                return true;
            if(matrix[mid][n-1] > target){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(lo == m)
            return false;
        
        int row = lo;
        lo = 0;
        hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[row][mid] == target)
                return true;
            if(matrix[row][mid] > target){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return false;
    }
};
