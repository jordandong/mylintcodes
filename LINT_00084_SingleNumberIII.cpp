/*
Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

Example
Given [1,2,2,3,4,4,5,3] return 1 and 5

Challenge
O(n) time, O(1) extra space.
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int diff = 0;
        vector<int> res(2, 0);
        for(int e : A)
            diff^=e;//get all the different bits bewteen those two numbers
        
        //get one different bit between those two numbers
        diff = diff & (diff ^ (diff - 1));
        for(int e : A)
            ((e&diff) == 0 ? res[0]:res[1]) ^= e;
        return res;
    }
};
