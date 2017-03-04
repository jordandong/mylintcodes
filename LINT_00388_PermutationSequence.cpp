/*
Given n and k, return the k-th permutation sequence.

Example
For n = 3, all permutations are listed as follows:

"123"
"132"
"213"
"231"
"312"
"321"
If k = 4, the fourth permutation is "231"

Note
n will be between 1 and 9 inclusive.

Challenge
O(n*k) in time complexity is easy, can you do it in O(n^2) or less?

Tags Expand 
Permutation Array
*/

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        if(n <= 0 || k <= 0)
            return "";
        long long fac = 1;
        string p(n, '0');
        string res = "";
        for(int i = 1; i <= n; i++){
            fac *= i;
            p[i - 1] = ('0' + i);//index start from 0
        };
        
        // change range of k from (1,n) to (0, n-1) to adapt the index in p
        k--;
        for (int i = n; i >= 1; i--){
            // divide fact first
            fac /= i;
            res.push_back(p[k/fac]); //d0 = k / (n-1)!, also k2 = k % (n-1)!, d1 = k2 % (n-2)!...
            p.erase(k/fac, 1); //remove the used num
            k %= fac; //left k
        };
        return res;
    }
};
