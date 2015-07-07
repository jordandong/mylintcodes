/*
On one line there are n houses. Give you an array of integer means the the position of each house. Now you need to pick k position to build k post office, so that the sum distance of each house to the nearest post office is the smallest. Return the least possible sum of all distances between each village and its nearest post office.

Have you met this question in a real interview? Yes

Example
Given array a = [1,2,3,4,5], k = 2. return 3.

Challenge
Could you solve this problem in O(n^2) time ?
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        int N = A.size();
        if (N == 0 || k >= N)
            return 0;

        sort(A.begin(), A.end()); //O(NlogN)

        // Time: O(k*N^2)
        // Space: O(N^2)
        vector<vector<int>> cost(N + 1, vector<int>(N + 1, 0));
        min_sum_i_to_j(A, cost);

        // Time: O(k*N^2)
        // Space: O(N)
        // sum[i][j] denotes the smallest sum of picking i post offices for the first j houses.
        vector<vector<int>> sum(2, vector<int>(N + 1, INT_MAX));
        sum[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int r = 1; r <= j; ++r) {
                    if (sum[(i - 1) % 2][j - r] != INT_MAX) {
                        sum[i % 2][j] = min(sum[i % 2][j],
                                            sum[(i - 1) % 2][j - r] +
                                            cost[j - r + 1][j]);
                    }
                }
            }
        }
        return sum[k % 2][N];
    }

    void min_sum_i_to_j(vector<int>& A, vector<vector<int>> &cost) {
        // Min cost of building a post office between house (i, j).
        // This post office must be in median position.
        int N = A.size();
        int i, j;
        for (int mid = 0; mid < N; mid++) {
            i = mid;
            j = mid;
            while (i >= 0 && j < N) {
                if (i - 1 >= 0) {
                    cost[i][j + 1] = cost[i + 1][j + 1] + A[mid] - A[i - 1];
                }
                if (j + 1 < N) {
                    cost[i + 1][j + 1 + 1] = cost[i + 1][j + 1] + A[j + 1] - A[mid];
                }
                i--;
                j++;
                if (i >= 0 && j < N) {
                    cost[i + 1][j + 1] = cost[i + 2][j] + A[j] - A[i];
                }
            }
        }
    }
};
