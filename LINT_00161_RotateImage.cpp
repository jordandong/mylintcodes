/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Example
Given a matrix [[1,2],[3,4]], rotate it by 90 degrees (clockwise), return [[3,1],[4,2]]

Challenge
Could you do this in-place?
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        int n = 0;
        if(m>0)
            n = matrix[0].size();
        else
            return;
        if(n==0)
            return;
            
        int i = 0;
        int j = n-1;
        while(i<j){
            for(int k=0;k<n;k++){
                swap(matrix[i][k], matrix[j][k]);
            }
            i++;
            j--;
        }
        
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
