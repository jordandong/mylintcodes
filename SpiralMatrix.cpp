/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Have you met this question in a real interview? Yes

Example
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

Tags Expand 
Array Matrix
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> res;
        int m = matrix.size();
        if(m <= 0)
            return res;
        int n = matrix[0].size();
        if(n <= 0)
            return res;
        int offset = 0;
        while(m > 0 && n > 0){
            if(m == 1){
                for(int j = 0; j < n; j++)
                    res.push_back(matrix[offset][offset + j]);
                return res;
            }
            if(n == 1){
                for(int i = 0; i < m; i++)
                    res.push_back(matrix[offset + i][offset]);
                return res;
            }
            
            int i = 0, j = 0;
            while(j < n - 1)
        	    res.push_back(matrix[offset + i][offset + j++]);
            while(i < m - 1)
        	    res.push_back(matrix[offset + i++][offset + j]);
            while(j > 0)
        	    res.push_back(matrix[offset + i][offset + j--]);
            while(i > 0)
        	    res.push_back(matrix[offset + i--][offset + j]);
        	m -= 2;
        	n -= 2;
        	offset += 1;
        }
        return res;
    }
};
