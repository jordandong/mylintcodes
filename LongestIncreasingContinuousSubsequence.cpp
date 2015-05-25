/*
Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)
Have you met this question in a real interview? Yes

Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.
For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.

Note
O(n) time

Tags Expand 
Dynamic Programming Array
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int mx_lr = 0, mx_rl = 0;
        int cur_lr = 0, cur_rl = 0;
        for (int i = 0; i < A.size(); i++) {
            if (i == 0 || A[i] == A[i - 1]) {
                mx_lr = max(mx_lr, ++cur_lr);
                mx_rl = max(mx_rl, ++cur_rl);
            } else if (A[i] > A[i - 1]) {
                mx_lr = max(mx_lr, ++cur_lr);
                cur_rl = 1;
            } else {
                mx_rl = max(mx_rl, ++cur_rl);
                cur_lr = 1;
            }
        }
        return max(mx_lr, mx_rl);
    }
};
