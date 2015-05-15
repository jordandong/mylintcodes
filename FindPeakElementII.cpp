/*
There is an integer matrix which has the following features:

The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
We define a position P is a peek if A[j][i] > A[j+1][i] && A[j][i] > A[j-1][i] && A[j][i] > A[j][i+1] && A[j][i] > A[j][i-1].

Find a peak element in this matrix. Return the index of the peak.

Example
Given a matrix:
[
  [1 ,2 ,3 ,6 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,10],
  [13,14,11,10,9]
]
return index of 41 (which is [1,1]) or index of 24 (which is [2,2])

Note
The matrix may contains multiple peeks, find any of them.

Challenge
Solve it in O(n+m) time.

If you come up with an algorithm that you thought it is O(n log m) or O(m log n), can you prove it is actually O(n+m) or propose a similar but O(n+m) algorithm?

Tags Expand 
Binary Search LintCode Copyright Matrix
*/

//O(min(M, N)*log(max(M, N)))
class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        int M = A.size();
        if (M == 0)
            return {};
        int N = A[0].size();
        if (N == 0)
            return {};

        int mid, mx, mx_i, mx_j;
        if (N > M) {
            int lo = 0, hi = N - 1;
            while (lo <= hi) { //O(logN)
                mid = lo + (hi - lo)/2;
                mx = A[0][mid];
                mx_i = 0;
                for (int i = 0; i < M; i++) {//O(M)
                    if (A[i][mid] > mx) {
                        mx = A[i][mid];
                        mx_i = i; 
                    }
                }
                if(mid > 0 && A[mx_i][mid - 1] > mx)
                    hi = mid - 1;
                else if(mid < N - 1 && A[mx_i][mid + 1] > mx)
                    lo = mid + 1;
                else
                    return {mx_i, mid};	
            }
            return {mx_i, mid};	
        } else {
            int lo = 0, hi = M - 1;
            while (lo <= hi) { //O(logM)
                mid = lo + (hi - lo)/2;
                mx = A[mid][0];
                mx_j = 0;
                for (int j = 0; j < N; j++) {//O(N)
                    if (A[mid][j] > mx) {
                        mx = A[mid][j];
                        mx_j = j; 
                    }
                }
                if(mid > 0 && A[mid - 1][mx_j] > mx)
                    hi = mid - 1;
                else if(mid < M - 1 && A[mid + 1][mx_j] > mx)
                    lo = mid + 1;
                else
                    return {mid, mx_j};	
            }
            return {mid, mx_j};	
        }
    }
};

//O(M*N)
class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        int M = A.size();
        if (M == 0)
            return {};
        int N = A[0].size();
        if (N == 0)
            return {};
        int i = 0, j = 0;
        while (true) {
            if( is_bigger(i - 1, j, A[i][j], A) ) {
                i--;
                continue;
            }
            if( is_bigger(i + 1, j, A[i][j], A) ) {
                i++;
                continue;
            }
            if( is_bigger(i, j - 1, A[i][j], A) ) {
                j--;
                continue;
            }
            if( is_bigger(i, j + 1, A[i][j], A) ) {
                j++;
                continue;
            }
            break;
        }
        return {i, j};
    }
    
    bool is_bigger(int i, int j, int val, vector<vector<int> > &A) {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
            return false;
        return A[i][j] > val;
    }
};
