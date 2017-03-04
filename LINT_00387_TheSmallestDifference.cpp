/*
Given two array of integers(the first array is array A, the second array is array B), now we are going to find a element in array A which is A[i], and another element in array B which is B[j], so that the difference between A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.

Example
For example, given array A = [3,4,6,7], B = [2,3,8,9], return 0

Challenge
O(n log n) time

Tags Expand 
Two Pointers Sort Array
Given two array of integers(the first array is array A, the second array is array B), now we are going to find a element in array A which is A[i], and another element in array B which is B[j], so that the difference between A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.

Example
For example, given array A = [3,4,6,7], B = [2,3,8,9], return 0

Challenge
O(n log n) time

Tags Expand 
Two Pointers Sort Array
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int NA = A.size();
        if(NA == 0)
            return 0;
        int NB = B.size();
        if(NB == 0)
            return 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int res = INT_MAX;
        while(NA > 0 && NB > 0){
            if(A[NA - 1] > B[NB - 1]){
                res = min(res, A[NA - 1] - B[NB - 1]);
                NA--;
            }else{
                res = min(res, B[NB - 1] - A[NA - 1]);
                NB--;
            }
        }
        return res;
    }
};
