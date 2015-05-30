/*
Given an integer array, find a subarray where the sum of numbers is between two given interval. Your code should return the number of possible answer.

Have you met this question in a real interview? Yes

Example
Given [1,2,3,4] and interval = [1,3], return 4. The possible answers are:
[0, 0]
[0, 1]
[1, 1]
[3, 3]

Tags Expand 
Two Pointers Array
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // Write your code here
        int N = A.size();
        vector<int> sums(N + 1, 0);
        for (int i = 0; i < N; i++)
            sums[i + 1] = sums[i] + A[i];
        
        int res = 0;
        int i = 0, j = 1;
        while (j <= N) {
            if ( i == j || sums[j] - sums[i] < start) {
                j++;
            } else if (sums[j] - sums[i] > end) {
                i++;
            } else {
                int tmp_j = j;
                while (start <= sums[tmp_j] - sums[i] && sums[tmp_j] -sums[i] <= end && tmp_j <= N) {
                    res++;
                    tmp_j++;
                }
                i++;
            }
        }
        return res;
    }
};
