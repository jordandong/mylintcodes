/*
Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)

Have you met this question in a real interview? Yes

Example
Give [-3, 1, 3, -3, 4], return [1,4].

Tags Expand 
Subarray Array
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int N = A.size();
        if (N == 0)
            return {-1, -1};
        int start = 0;
        int sum = 0;
        int mx = A[0];
        vector<int> res(2, 0);
        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (sum > mx) {
                mx = sum;
                res[0] = start;
                res[1] = i;
            }
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        return res;
    }
};
