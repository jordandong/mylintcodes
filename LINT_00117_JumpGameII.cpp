/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int mi = 0;
        int sz = A.size();
        int end = sz - 1;
        
        while(end > 0){
            for(int i = 0; i < sz; i++ ){
                if(i + A[i] >= end){
                    end = i;
                    mi++;
                    break;
                }
            }
        }
        return mi;
    }
};
