/*
Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.
Example
Given [1,1,2,3,3,3,2,2,4,1] return 4
Challenge
One-pass, constant exstra space
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        vector<int> bmp(32, 0);
        int res = 0;
        for(int e : A){
            for(int i=0; i<32; i++){
                if((e>>i)&0x00000001){
                    bmp[i]++;
                }
            }
        }
        for(int i=0; i<32; i++){
            if(bmp[i]%3){
                res|=(0x00000001<<i);
            }
        }
        return res;
    }
};
