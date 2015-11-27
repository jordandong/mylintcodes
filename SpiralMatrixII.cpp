/*
Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

Have you met this question in a real interview? Yes

Example
Given n = 3,
You should return the following matrix:
[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

Note
Tags Expand 
Array
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int> > res(n, vector<int>(n, 0));
        int x = 1;
        int offset = 0;
        while(n > 0){
            if(n == 1){
                for(int j = 0; j < n; j++)
                    res[offset][offset + j] = x++;
                return res;
            }
            
            int i = 0, j = 0;
            while(j < n - 1)
        	    res[offset + i][offset + j++] = x++;
            while(i < n - 1)
        	    res[offset + i++][offset + j] = x++;
            while(j > 0)
        	    res[offset + i][offset + j--] = x++;
            while(i > 0)
        	    res[offset + i--][offset + j] = x++;
            n -= 2;
            offset += 1;
        }
        return res;
    }
};
