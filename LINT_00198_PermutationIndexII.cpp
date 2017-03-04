/*
Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.

Have you met this question in a real interview? Yes

Example
Given the permutation [1, 4, 2, 2], return 3.
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here

        int N = A.size(); 
        long long fac = 1;
        long long index = 1;
        unordered_map<int, int> num_cnt;

        for (int i = N - 1; i >= 0; i--) {
            unordered_map<int, int> small_num_cnt;
            num_cnt[A[i]]++;
            for (int j = i + 1; j < N; j++) {
                if (A[i] > A[j]) { //count smaller elements after i
                    small_num_cnt[A[j]]++;
                }
            }
            for (auto &kv : small_num_cnt) {
                index += (fac * kv.second / num_cnt[A[i]]);
                //the last fac needs to substract the duplication caused by A[i]
                // (N - i - 2)!/(a!b!c!) --> (N - i - 2)!/((a - 1)!(b + 1)!c!) --> fac * a / num_cnt[A[i]]
            
            }
            //similarly, (N - i - 1)!/(a!b!c!) --> (N - i)!/((a+1)!b!c!) --> fac * (N - i) / num_cnt[A[i]]
            //the total combination of last N - i e;ments without duplication
            fac = fac * (N - i) / num_cnt[A[i]];
        }
        return index;
    }
};
