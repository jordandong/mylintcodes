/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Notice
1. You may assume that the matrix does not change.
2. There are many calls to sumRegion function.
3. You may assume that row1 ≤ row2 and col1 ≤ col2.

Example
Given matrix =
[
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Tags 
Dynamic Programming
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        M = matrix.size();
        if (M == 0)
            return;
        N = matrix[0].size();
        if (N == 0)
            return;
        dp = new long long*[M + 1];
        memset(dp, 0, sizeof(long long)* (M + 1));
        for (int i = 0; i <= M; ++i) {
            dp[i] = new long long[N + 1];
            memset(dp[i], 0, sizeof(long long)* (N + 1));
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
    }
    
    ~NumMatrix() {
        if (M == 0 || N == 0)
            return;
        for (int i = 0; i <= M; ++i)
            delete dp[i];
        delete dp;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] -
                dp[row1][col2 + 1] + dp[row1][col1];
    }

private:
    long long **dp;
    int M;
    int N;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
