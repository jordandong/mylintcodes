/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Example
Given [4,5,6,7,0,1,2] return 0
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int lo = 0;
        int hi = num.size() - 1;
        if(hi<0)
            return -1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(num[mid] > num[hi]){
                lo = mid +1;
            }else{
                hi = mid;
            }
        }
        return num[lo];
    }
};
