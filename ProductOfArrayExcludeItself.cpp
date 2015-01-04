/*
Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B without divide operation.

Example
For A=[1, 2, 3], B is [6, 3, 2]
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<long long> res(n, 1);
        long long tmp = 1;
        if(n==1){
            res.clear();
            return res;
        }
 
        for(int i = 0; i < n; i++) {
            if(i==0){
                res[i]=nums[i];
            }else{
                res[i]=res[i-1]*nums[i];
            }
        }

        for(int j = n-1; j >= 0; j--){
            if(j==0){
                res[j] = tmp;
            }else{
                res[j] = res[j-1]*tmp;
            }
            tmp*=nums[j];
        }

        return res;
    }
};
