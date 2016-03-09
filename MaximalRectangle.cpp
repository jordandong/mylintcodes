/*
Given a 2D boolean matrix filled with False and True, find the largest rectangle containing all True and return its area.

Have you met this question in a real interview? Yes

Example
Given a matrix:
[
  [1, 1, 0, 0, 1],
  [0, 1, 0, 0, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 0, 0, 1]
]
return 6.

Tags
Dynamic Programming Array Stack
*/

//O(M*2*N)
class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        if(n == 0)
            return 0;

        vector<int> H(n);
        vector<int> L(n);
        vector<int> R(n, n);

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    ++H[j];	//keep the height at right bottom i,j
                    L[j] = max(L[j], left);	//keep the satrt left pos with true
                }else {
                    left = j + 1;
                    H[j] = 0;
                    L[j] = 0;
                    R[j] = n;
                }
            }
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j]) {	//keep the end right pos with true at right bottom i,j
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j] - L[j]));
                }else {
                    right = j;
                }
            }
        }
        return ret;
    }
};
