/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.

Example
Given a matrix:

[
  [1, 2,  3,  4],
  [5, 6,  7,  8],
  [9,10, 11, 12]
]
return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]

Tags Expand 
LintCode Copyright Matrix
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> res;  
        int M = matrix.size();
        if(M == 0)
            return res;
        int N = matrix[0].size();
        if(N == 0)
            return res;
        int flag = true;
        int r = 0, c = 0;
        while(r < M && c < N){
            res.push_back(matrix[r][c]);
            if(flag){
                if(c == N - 1){
                    r++;
                    flag = false;
                }else if(r == 0){
                    c++;
                    flag = false;
                }else{
                    r--;
                    c++;
                }
            }else{
                if(r == M - 1){
                    c++;
                    flag = true;
                }else if(c == 0){
                    r++;
                    flag = true;
                }else{
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};
