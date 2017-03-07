/*
Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(NlogN) algorithm.

Example,
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].

Tags,
Quick Sort Sort Merge Sort
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        int N = A.size();
        if (N == 0)
            return;
        sortIntegers2Helper(A, 0, N -1);
    }
    
    void sortIntegers2Helper(vector<int>& A, int s, int e) {
        if (s >= e)
            return;
        int i = s, j = e - 1;
        while (i <= j) {
            if (A[i] >= A[e]) {
                swap(A[i], A[j--]);
            } else if (A[j] < A[e]) {
                swap(A[i++], A[j]);
            } else {
                i++;
                j--;
            }
        }
        swap(A[i], A[e]);
        sortIntegers2Helper(A, s, i - 1);
        sortIntegers2Helper(A, i + 1, e);
    }
};
