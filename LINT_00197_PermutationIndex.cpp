/*
Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.

Have you met this question in a real interview? Yes

Example
Given [1,2,4], return 1.
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        
        int N = A.size(); 
        long long fac = 1;
        long long index = 1;

        for (int i = N - 1; i >= 0; i--) {
            int cnt = 0;
            for (int j = i + 1; j < N; j++) {
                //if using merge and sort to count the smaller elements
                //T: O(NlogN) , S: O(N)
                if (A[i] > A[j]) //count smaller elements after i
                    cnt++;
            }
            index += cnt * fac;
            fac *= (N - i);
        }
        return index;
    }
};
