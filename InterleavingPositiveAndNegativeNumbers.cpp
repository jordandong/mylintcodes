/*
Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.
Note:
You are not necessary to keep the original order or positive integers or negative integers.

Example:
Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other legal answer.

Challenge:
Do it in-place and without extra memory.
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        // write your code here
        int sz = A.size();
        if(sz < 3)
            return A;
        
        int neg_cnt = 0;
        bool started_neg = false;
        int i = 0;
        int j = 1;
        
        for(int a : A)
            neg_cnt+=(a<0?1:0);
        if(neg_cnt > sz/2)
            started_neg = true;
        
        do{
            while(A[i]<0 == started_neg)
                i+=2;
            while(A[j]>0 == started_neg)
                j+=2;
            if(i >=sz || j>=sz)
                break;
            swap(A[i], A[j]);
            i+=2;
            j+=2;
        }while(i<sz && j<sz);
        
        return A;
    }
};
