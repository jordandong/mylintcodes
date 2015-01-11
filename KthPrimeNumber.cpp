/*
Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.

The eligible numbers are like 3, 5, 7, 9, 15 ...

Example:
If k=4, return 9.

Challenge:
O(n log n) or O(n) time
*/

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        long long res[k + 1];
        res[0] = 1;
        int base3_idx=0, base5_idx=0, base7_idx=0;
        for(int i = 1; i <= k; i++){
            long long v = min(min(res[base3_idx]*3, res[base5_idx]*5), res[base7_idx]*7);
            
            //if the minimum is used, increasing the base in order to generate bigger one in next round
            if(v/res[base3_idx] == 3)
                base3_idx++;
            if(v/res[base5_idx] == 5)
                base5_idx++;
            if(v/res[base7_idx] == 7)
                base7_idx++;
                
            res[i] = v;
        }
        return res[k];
    }
};
