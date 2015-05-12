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
  [1 ,2 ,3 ,4 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,8],
  [13,12,11,10,9]
]
return index of 41 (which is [1,1]) or index of 24 (which is [2,2])

Note
The matrix may contains multiple peeks, find any of them.

Challenge
Solve it in O(n) time.

If you come up with an algorithm that you thought it is O(n log n), can you prove it is actually O(n) or propose a similar but O(n) algorithm?

Tags Expand 
Binary Search LintCode Copyright Matrix
*/

//It is O(n), Cannot Pass Case 15 LTE 
class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        vector<int> res;
        int M = A.size();
        if (M == 0)
            return res;
        int N = A[0].size();
        if (N == 0)
            return res;
        findPeakIIHelper(0, M - 1, 0, N - 1, A, res);
        return res;
    }
    
    void findPeakIIHelper(int li, int hi, int lj, int hj, vector<vector<int> > &A, vector<int> &res) {
        while(true) {
        
        if(hj == lj && hi == li){
            res.push_back(li);
            res.push_back(lj);
            return;
        }
            
        if(hj - lj >= hi - li){
            int mid = lj + (hj - lj)/2;
            int mx = A[li][mid];
            int mx_i = li;
            for (int i = li; i <= hi; i++) {
                if (A[i][mid] > mx) {
                    mx = A[i][mid];
                    mx_i = i; 
                }
            }
            if (mid > 0 && A[mx_i][mid - 1] > mx ) {
                hj = mid - 1;
                //findPeakIIHelper(li, hi, lj, mid - 1, A, res);
            } else if (mid < A[0].size() - 1 && A[mx_i][mid + 1] > mx ) {
                lj = mid + 1;
                //findPeakIIHelper(li, hi, mid + 1, hj, A, res);
            } else {
                res.push_back(mx_i);
                res.push_back(mid);
                return;
            }
        }else{
            int mid = li + (hi - li)/2;
            int mx = A[mid][lj];
            int mx_j = lj;
            for (int j = lj; j <= hj; j++) {
                if (A[mid][j] > mx) {
                    mx = A[mid][j];
                    mx_j = j; 
                }
            }
            if (mid > 0 && A[mid - 1][mx_j] > mx ) {
                //findPeakIIHelper(li, mid - 1, lj, hj, A, res);
                hi = mid - 1;
            } else if (mid < A.size() - 1 && A[mid + 1][mx_j] > mx ){
                //findPeakIIHelper(mid + 1, hi, lj, hj, A, res);
                li = mid + 1;
            } else {
                res.push_back(mid);
                res.push_back(mx_j);
                return;
            }
        }
        }
    }
};
