/*
Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) . For each element Ai in the array, count the number of element before this element Ai is smaller than it and return count number array.

Example
For array [1,2,7,8,5], return [0,1,2,3,2]

Note
We suggest you finish problem Segment Tree Build, Segment Tree Query II and Count of Smaller Number before itself I first.

Tags Expand 
LintCode Copyright Binary Tree Segment Tree
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        int N = A.size();
        vector<int> res(N, 0);
        if(N == 0)
            return res;
        countOfSmallerNumberIIHelper(A, 0, N - 1, res);//Merge and Sort
        return res;
    }
    
    vector<int> countOfSmallerNumberIIHelper(vector<int> &A, int s, int e, vector<int> &res) {
        vector<int> rtn;
        if(s == e){
            rtn.push_back(s);
            return rtn;
        }
        
        vector<int> l, r;
        int mid = s + (e - s)/2;
        l = countOfSmallerNumberIIHelper(A, s, mid, res);
        r = countOfSmallerNumberIIHelper(A, mid + 1, e, res);
        int i = 0, j = 0;
        while(i < l.size() && j < r.size()){
            if(A[l[i]] < A[r[j]]){
                rtn.push_back(l[i]);//sort the value, but store the index
                i++;
            }else{
                rtn.push_back(r[j]);
                res[r[j]] += i;//record the conuts of smaller values in the left part
                j++;
            }
        }
        while(j < r.size()){
            rtn.push_back(r[j]);
            res[r[j]] += i;//record the conuts of smaller values in the left part
            j++;
        }
        while(i < l.size()){
            rtn.push_back(l[i]);
            i++;
        }
        return rtn;
    }
};
