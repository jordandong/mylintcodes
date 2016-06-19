/*
Given an integer array, sort it in ascending order. Use selection sort, bubble sort, insertion sort or any O(N^2) algorithm.

Example,
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].

Tags,
Sort
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        int N = A.size();
        if (N == 0)
            return;
        
        for (int i = 0; i < N; i++) {
            int mi = A[i];
            int idx = i;
            for (int j = i; j < N; j++) {
                if (A[j] < mi) {
                    mi = A[j];
                    idx = j;
                }
            }
            swap(A[i], A[idx]);
        }
    }
};
