/*
Given n pieces of wood with length L[i] (integer array).
Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

Note:
You couldn't cut wood into float length.

Example:
For L=[232, 124, 456], k=7, return 114.

Challenge:
O(n log Len), where Len is the longest length of the wood.
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int p = 0;
        int lo = 1;
        int hi = 0;
        int mx_l = 0;
        for(int e : L)
            hi = max(hi, e);

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            p = 0;
            for(int e : L)
                p += (e/mid);
            if(p < k){
                hi = mid - 1;
            }else{
                mx_l = mid;
                lo = mid + 1;
            }
        }
        return mx_l;
    }
};
