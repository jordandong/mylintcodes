/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

Have you met this question in a real interview? Yes

Example
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

Tags Expand 
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int M = matrix.size();
        if (M == 0)
            return 0;
        int N = matrix[0].size();
        if (N == 0)
            return 0;
        vector<int> V(N, 0);
        vector<int> S(N, 0);
        int maxSide = 0;
        
        for (int i = 0; i < M; i++) {
            int H = 0; 
            int Sj_1 = 0;
            for (int j = 0; j < N; j++) {
                //ending at (i, j), the longest horizontal and vertical side
                H = (matrix[i][j] == 1) ? (H + 1) : 0;
                V[j] = (matrix[i][j] == 1) ? (V[j] + 1) : 0;
                //Sj_1 is the maxSide last time ending at (i-1, j-1) 
                int newSj = min(Sj_1 + 1, min(H, V[j]));
                Sj_1 = S[j];
                S[j] = newSj;
                if (maxSide < S[j])
                    maxSide = S[j];
           }
        }
        return maxSide*maxSide;
    }
};
