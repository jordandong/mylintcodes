/*
For an array A, if i < j, and A [i] > A [j], called (A [i], A [j]) is a reverse pair.
return total of reverse pairs in A.

Example,
Given A = [2, 4, 1, 3, 5] , (2, 1), (4, 1), (4, 3) are reverse pairs. return 3

Tags,
Array Merge Sort
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        long long res = 0;
        reversePairsHelper(A, 0, A.size() - 1, res);
        return res;
    }
    
    vector<int> reversePairsHelper(vector<int>& A, int s, int e, long long &res) {
        if (s > e)
            return {};
        if (s == e)
            return {A[s]};
        int m = s + (e - s)/2;
        vector<int> l = reversePairsHelper(A, s, m, res);
        vector<int> r = reversePairsHelper(A, m + 1, e, res);
        int i = 0, j = 0;
        vector<int> rnt;
        while (i < l.size() && j < r.size()) {
            if (l[i] > r[j]) {
                rnt.push_back(l[i++]);
                res += (r.size() - j);
            } else {
                rnt.push_back(r[j++]);
            }
        }
        while (i < l.size())
            rnt.push_back(l[i++]);
        while (j < r.size())
            rnt.push_back(r[j++]);
        return rnt;
    }
};
