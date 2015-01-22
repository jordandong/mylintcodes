/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example:
For A = [1,2,3,4,5,6] B = [2,3,4,5], the median is 3.5
For A = [1,2,3] B = [4,5], the median is 3

Challenge:
Time Complexity O(logn)
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int sz_a = A.size();
        int sz_b = B.size();
        int sz = sz_a + sz_b;
        if((sz % 2) ==  1){
            return (double)findKth(A, 0, sz_a, B, 0, sz_b, sz/2 + 1); 
        }else{
            return (findKth(A, 0, sz_a, B, 0, sz_b, sz/2) + findKth(A, 0, sz_a, B, 0, sz_b, sz/2 + 1))/2.0;
        }
    }
    
    int findKth(vector<int> &A, int s_a, int l_a, vector<int> &B, int s_b, int l_b, int k){
        
        if(l_a > l_b)
            return findKth(B, s_b, l_b, A, s_a, l_a, k);

        if(l_a == 0)
            return B[s_b + k - 1];
        if(k == 1)
            return min(A[s_a], B[s_b]);

        //log(k)
        int pos_a = min(k/2, l_a);
        int pos_b = k - pos_a;
        if(A[s_a + pos_a - 1] == B[s_b + pos_b - 1])
            return A[s_a + pos_a - 1];

        if(A[s_a + pos_a - 1] > B[s_b + pos_b - 1]){
            return findKth(A, s_a, l_a, B, s_b + pos_b, l_b - pos_b, k - pos_b);
        }else{
            return findKth(A, s_a + pos_a, l_a - pos_a, B, s_b, l_b, k - pos_a);
        }
    }
};
