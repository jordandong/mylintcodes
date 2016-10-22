/*
Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. For each query, give you an integer, return the number of element in the array that are smaller that the given integer.

Example
For array [1,2,7,8,5], and queries [1,8,5], return [0,4,2]

Note
We suggest you finish problem Segment Tree Build and Segment Tree Query II first.

Challenge
Could you use three ways to do it.
1. Just loop
2. Sort and binary search
3. Build Segment Tree and Search.

Tags Expand 
Binary Search Segment Tree
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> res;
        int N = A.size();
        if(N > 0)
            sort(A.begin(), A.end());
        for(auto e : queries)
            res.push_back(countOfSmallerNumberQuery(A, e));
        return res;
    }
    
    int countOfSmallerNumberQuery(vector<int> &A, int v){
        int lo = 0;
        int hi = A.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(A[mid] < v)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }
};
