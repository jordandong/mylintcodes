/*
Given an integer matrix, find a submatrix where the sum of numbers is zero. Your code should return the coordinate of the left-up and right-down number.

Have you met this question in a real interview? Yes

Example
Given matrix
[
  [1 ,5 ,7],
  [3 ,7 ,-8],
  [4 ,-8 ,9],
]
return [(1,1), (2,2)]

Challenge
O(n^3) time.

Tags Expand 
Enumeration Matrix
*/

//T:O(min(M, N)^2 * max(M, N)), S:O(max(M, N))
class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        int M = matrix.size();
        if (M == 0)
            return {{-1, -1}, {-1, -1}};
        int N = matrix[0].size();
        if (N == 0)
            return {{-1, -1}, {-1, -1}};
        
        if (M <= N ) {
            for (int up = 0; up < M; up++) {
                vector<int> square_sum(N, 0);
                for (int down = up; down < M; down++) {
                    int row_sum = 0;
                    for (int j = 0; j < N; j++) {
                        row_sum += matrix[down][j];  //sum from (down, 0) to (down, j)
                        square_sum[j] += row_sum;  //square sum from (up, 0) to (down, j)
                    }

                    auto left_right = zeroSum(square_sum); //find left and right index to make subsum == 0
                    if (left_right.size())
                        return {{up, left_right[0]}, {down, left_right[1]}};
                }
            }
        } else {
            for (int left = 0; left < N; left++) {
                vector<int> square_sum(M, 0);
                for (int right = left; right < N; right++) {
                    int col_sum = 0;
                    for (int i = 0; i < M; i++) {
                        col_sum += matrix[i][right];  //sum from (0, right) to (i, right)
                        square_sum[i] += col_sum; //square sum from (0, left) to (i, right)
                    }

                    auto up_down = zeroSum(square_sum); //find up and down index to make subsum == 0
                    if (up_down.size())
                        return {{up_down[0], left}, {up_down[1], right}};
                }
            }
        }
        return {{-1, -1}, {-1, -1}};
    }

    vector<int> zeroSum(vector<int>& A) {
        unordered_map<int, int> mp;
        for (int k = 0; k < A.size(); k++) {
            if (A[k] == 0)
                return {0, k};
            else if (mp.find(A[k]) != mp.end())
                return {mp[A[k]] + 1, k};
            else
                mp[A[k]] = k;
        }
        return {};
    }
};
