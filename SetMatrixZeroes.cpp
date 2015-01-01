/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Example
Given a matrix [[1,2],[0,3]], return [[0,2],[0,0]]

Challenge
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        if(n == 0)
            return;
        bool last_flag = false;
        bool curr_flag = false;

        for(int i = 0; i < m; i++){
            curr_flag = false;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    int r = i;
                    while(r>0)
                        matrix[--r][j] = 0;//reset all row in this col
                    curr_flag = true;
                }else{
                    if(i>0 && matrix[i-1][j] == 0) //reset if last row is zero
                        matrix[i][j] = 0;
                    if(last_flag) //reset last row if last row reset flag is set
                        matrix[i-1][j] = 0;
                }
            }
            last_flag = curr_flag;
        }
        
        if(last_flag){//reset last row
            for(int j =0; j<n; j++)
                matrix[m-1][j] = 0;
        }
        
    }
};
