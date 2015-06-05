/*
Given an integer array, find a continuous rotate subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)

Have you met this question in a real interview? Yes

Example
Give [3, 1, -100, -3, 4], return [4, 1].

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
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        int N = A.size();
        if (N == 0)
            return {-1, -1};
        
        //find max without rotate
        int mx1 = 0; 
        vector<int> res1 = continuousSubarraySum(A, mx1);
        if (mx1 <= 0) //all negative
            return res1;

        //flip sign
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            A[i] = -A[i];
        }
        
        //find max without rotate using opposited sign
        //if rotated subarray is max, there must be a min sum(<0) in the middle, after flip sign, it is max sum(>0)
        int mx2 = 0;
        vector<int> res2 = continuousSubarraySum(A, mx2);
        mx2 += sum;

        if (mx1 >= mx2) {
            return res1;
        }else{
            swap(res2[0], res2[1]);
            res2[0] = (res2[0] + 1)%N;
            res2[1] = (res2[1] - 1)%N;
            return res2;
        }
    }
  
    vector<int> continuousSubarraySum(vector<int>& A, int &mx) {
        int start = 0;
        int sum = 0;
        mx = A[0];
        vector<int> res(2, 0);
        for (int i = 0; i < A.size(); i++) {
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
